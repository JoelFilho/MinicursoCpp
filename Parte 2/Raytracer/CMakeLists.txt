# Primeira linha de um projeto CMake indica a versão mínima necessária. Essa é suficiente. Ou não.
cmake_minimum_required(VERSION 3.10.0)

# Nome, versão e linguagem do projeto
project(Raytracer VERSION 0.1.0 LANGUAGES CXX)

# Bibliotecas que utilizamos neste projeto, importadas no vcpkg.
# Neste passo, apenas buscamos as bibliotecas.
find_package(fmt CONFIG REQUIRED)           # Biblioteca referência para std::format do C++20. Formatação mais legível de strings.
# Criamos um arquivo executável com src/main.cpp
add_executable(raytracer src/main.cpp)

# Indicamos que vamos utilizar C++17
target_compile_features(raytracer PRIVATE cxx_std_17)

# Adicionamos a pasta include para encontrarmos os arquivos sem necessitar adicionar caminhos relativos, como "../include/" no código.
target_include_directories(raytracer PRIVATE 
  include
)

# O executável é linkado com as bibliotecas que buscamos, utilizando os targets definidos por elas.
target_link_libraries(raytracer PRIVATE 
  fmt::fmt-header-only          # Forma moderna de adicionar bibliotecas. Estamos utilizando a versão header-only fornecida pela fmt.
)

