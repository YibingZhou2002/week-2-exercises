#include <memory>
#include <iostream>
#include <vector>

/**
 * A simple class which just reports when it is created (constructor) and when it is destroyed (destructor).
*/
class Reporter
{
    public: 
    Reporter(std::string id_string) : ID(id_string)
    {
        std::cout << "Creating Reporter Object with ID: " << ID << std::endl;
    }

    ~Reporter()
    {
        std::cout << "Destroying Reporter Object with ID: " << ID << std::endl;
    }

    private:
    std::string ID;
};

int main()
{
    // Raw pointer
    Reporter* rawPtr = new Reporter("RawPointer");
    // Clean up raw pointer
    delete rawPtr;

    // 使用 unique_ptr
    std::unique_ptr<Reporter> uniquePtr = std::make_unique<Reporter>("UniquePointer");

    // 使用 shared_ptr
    std::shared_ptr<Reporter> sharedPtr1 = std::make_shared<Reporter>("SharedPointer1");
    std::shared_ptr<Reporter> sharedPtr2 = sharedPtr1;  // 共享所有权

    // 使用 weak_ptr
    std::weak_ptr<Reporter> weakPtr = sharedPtr1;  // 弱引用，不影响生命周期

    return 0;
}