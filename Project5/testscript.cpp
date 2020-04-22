#include <iostream>
#include <vector>
void function(std::vector<std::string> &addedCity);
int main()
{
    std::vector<std::string> addedCity;
    for (int i = 0; i <= 50; i++)
    {
        for (int j = 0; j <= 150; j++)
        {
            function(addedCity);
        }
        std::cout << "clear" << std::endl;
        addedCity.resize(0);
    }
    return 0;
}
void function(std::vector<std::string> &addedCity)
{
    std::string inputArray[9] = {"i", "setd", "s", "degree", "graph_nodes", "graph_edges", "d", "shortest_d", "print_path"};
    std::string randomInput = inputArray[std::rand() % 9];
    if (randomInput == "i")
    {
        std::string city = "city";
        city += std::to_string(std::rand() % 10);
        addedCity.push_back(city);
        std::cout << "i "
                  << city << std::endl;
    }
    if (randomInput == "setd")
    {
        int dice = std::rand() % 13;
        std::string city1 = "city";
        std::string city2 = "city";
        if (dice <= 10)
        {
            if (addedCity.empty())
            {
                city1 += std::to_string(std::rand() % 10);
                city2 += std::to_string(std::rand() % 10);
            }
            else
            {
                city1 = addedCity[std::rand() % addedCity.size()];
                city2 = addedCity[std::rand() % addedCity.size()];
            }
        }
        else
        {
            city1 += std::to_string(std::rand() % 20);
            city2 += std::to_string(std::rand() % 20);
        }
        std::cout << "setd " << city1 << ";" << city2 << ";" <<(std::rand() % 50) * 0.7 << std::endl;
    }
    if (randomInput == "s")
    {
        int dice = std::rand() % 20;
        std::string city = "city";
        if (dice <= 10)
        {
            if (addedCity.empty())
            {
                city += std::to_string(std::rand() % 10);
            }
            else
            {
                city = addedCity[std::rand() % addedCity.size()];
            }
        }
        else
        {
            city += std::to_string(std::rand() % 20);
        }
        std::cout << "s " << city << std::endl;
    }

    if (randomInput == "degree")
    {
        int dice = std::rand() % 20;
        std::string city = "city";
        if (dice <= 10)
        {
            if (addedCity.empty())
            {
                city += std::to_string(std::rand() % 10);
            }
            else
            {
                city = addedCity[std::rand() % addedCity.size()];
            }
        }
        else
        {
            city += std::to_string(std::rand() % 20);
        }
        std::cout << "degree " << city << std::endl;
    }

    if (randomInput == "graph_nodes")
    {
        std::cout << "graph_nodes" << std::endl;
    }
    if (randomInput == "graph_edges")
    {
        std::cout << "graph_edges" << std::endl;
    }
    if (randomInput == "d")
    {
        int dice = std::rand() % 13;
        std::string city1 = "city";
        std::string city2 = "city";
        if (dice <= 10)
        {
            if (addedCity.empty())
            {
                city1 += std::to_string(std::rand() % 10);
                city2 += std::to_string(std::rand() % 10);
            }
            else
            {
                city1 = addedCity[std::rand() % addedCity.size()];
                city2 = addedCity[std::rand() % addedCity.size()];
            }
        }
        else
        {
            city1 += std::to_string(std::rand() % 20);
            city2 += std::to_string(std::rand() % 20);
        }
        std::cout << "d " << city1 << ";" << city2 << std::endl;
    }

    if (randomInput == "shortest_d")
    {
        int dice = std::rand() % 13;
        std::string city1 = "city";
        std::string city2 = "city";
        if (dice <= 10)
        {
            if (addedCity.empty())
            {
                city1 += std::to_string(std::rand() % 10);
                city2 += std::to_string(std::rand() % 10);
            }
            else
            {
                city1 = addedCity[std::rand() % addedCity.size()];
                city2 = addedCity[std::rand() % addedCity.size()];
            }
        }
        else
        {
            city1 += std::to_string(std::rand() % 20);
            city2 += std::to_string(std::rand() % 20);
        }
        std::cout << "shortest_d " << city1 << ";" << city2 << std::endl;
    }

    if (randomInput == "print_path")
    {
        int dice = std::rand() % 13;
        std::string city1 = "city";
        std::string city2 = "city";
        if (dice <= 10)
        {
            if (addedCity.empty())
            {
                city1 += std::to_string(std::rand() % 10);
                city2 += std::to_string(std::rand() % 10);
            }
            else
            {
                city1 = addedCity[std::rand() % addedCity.size()];
                city2 = addedCity[std::rand() % addedCity.size()];
            }
        }
        else
        {
            city1 += std::to_string(std::rand() % 20);
            city2 += std::to_string(std::rand() % 20);
        }
        std::cout << "print_path " << city1 << ";" << city2 << std::endl;
    }
}