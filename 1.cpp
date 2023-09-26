 
 template <typename T>
 struct sol {
    bool avl;
    int alt;
    T min , max;
 }

 template <typename T>
 sol<T> es_avl_rec (BinTree<T> const& arbol){
    if(arbol.empty())
        return {true,0,T(),T()};
    else{
        auto [avl_iz,alt_iz,min_iz,max_iz] = es_avl_rec(arbol.left());
        auto [avl_dr,alt_dr,min_dr,max_dr] = es_avl_rec(arbol.right());

        int alt = std::max (alt_iz,alt_dr) + 1;
        T max = arbol.right().empty() ? arbol.root() : max_dr; 
        T min = arbol.left().empty() ? arbol.root() : min_iz; 

        bool avl = avl_iz && avl_dr && abs(alt_iz-alt_dr) <= 1 && 
        (arbol.left().empty() || arbol.root() > max_iz ) && 
        (arbol.right().empty() || arbol.root() < min_dr );

        return {avl,alt,min,max}; 
    }
 }
 template <typename T>
 bool es_avl(BinTree<T> cosnt& arbol){
    return es_avl_rec(arbol).avl;
 }

 void resuelveCaso(){
    auto t = read_tree<int>(cin);
    if(es_avl(t)){
        //COUT
    }
    else{
        //COUT
    }
 }