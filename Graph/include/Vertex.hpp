#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex {
    private:
        int id;
    public:
        Vertex(): id(-1) {};
        Vertex(int id);
        int getId() const;
    
};

#endif