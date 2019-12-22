#include <iostream>
#include <string>
#include <vector>

void Log(const std::string& str)
{
	std::cout << str << std::endl;
}

class Entity
{
	private:
		int *i = nullptr;
		std::string str;
	public:
		Entity(int _i, const std::string& _str)
			:str(_str)
		{
			Log("Entity(int,string)");
			i = new int(_i);
		}
		Entity()
			:str("empty")
		{
			Log("Entity()");
			i = new int(-1);
		}
		~Entity()
		{
			Log("~Entity()");
			cleanup();
		}
		Entity(const Entity& src)
			:Entity(*(src.i), src.str)
		{
			Log("Entity(Entity&)");
		}
		Entity& operator=(const Entity& rhs)
		{
			Log("operator=(Entity&)");
			if(this == &rhs)
				return *this;
			Entity e(rhs);
			swap(*this,e);
			return *this;
		}
		friend void swap(Entity& first, Entity& second) noexcept
		{
			Log("swap(Entity,Entity)");
			using std::swap;
			swap(*(first.i), *(second.i));
			swap(first.str, second.str);
		}
		void cleanup() noexcept
		{
			delete i;
		}
		void moveFrom(Entity& src) noexcept
		{
			i = src.i;
			str = std::move(src.str); 
			
			src.i = nullptr;
		}
		//Move semantics : 원본 객체를 삭제할때만 유용함. 동적할당 메모리 사용시 꼭 작성해야함. 
		
		Entity(Entity&& src) noexcept
			:Entity()
		{
			Log("**move semantics** Entity(Entity&&)");
			//moveFrom(src);
			swap(*this,src);
		}
		Entity& operator=(Entity&& rhs) noexcept
		{
			Log("**move semantics** operator=(Entity&&)");
			if(this == &rhs)
				return *this;
			/*cleanup();
			moveFrom(rhs);*/
			Entity e(std::move(rhs));
			swap(*this,e);
			return *this;
		}
};

int main()
{
	Log("\nEntity e1");
	Entity e1;
	Log("\nEntity e2 = e1");
	Entity e2 = e1;
	Log("\nEntity e3");
	Entity e3;
	Log("\ne3 = e2");
	e3 = e2;
	{
		std::vector<Entity> vec;
		Log("\npush");
		vec.push_back(e1);
		Log("\n");
		vec.push_back(e2);
		Log("\n");
		vec.push_back(e3);
		Log("\nDestroy vec");
	}
	Log("\n");
	return 0;
}















