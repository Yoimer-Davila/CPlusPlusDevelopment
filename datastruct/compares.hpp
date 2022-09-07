namespace datastruct {

    template<typename Ty>
    struct compare {
        compare() {}
        virtual const bool __cdecl operator()(const Ty& right, const Ty& left) const = 0;
    };

    template<typename Ty>
    struct higher : public compare<Ty> {
        higher() : compare<Ty>() {}
        const bool __cdecl operator()(const Ty& right, const Ty& left) const { return right > left; }
    };

    template<typename Ty>
    struct lower : public compare<Ty> {
        lower() : compare<Ty>() {}
        const bool __cdecl operator()(const Ty& right, const Ty& left) const { return right < left; }
    };

    template<typename Ty>
    struct equals : public compare<Ty> {
        equals() : compare<Ty>() {}
        const bool __cdecl operator()(const Ty& right, const Ty& left) const { return right == left; }
    };

    template<typename Ty>
    struct higher_equal : public compare<Ty> {
        higher_equal() : compare<Ty>() {}
        const bool __cdecl operator()(const Ty& right, const Ty& left) const { return right >= left; }
    };

    template<typename Ty>
    struct lower_equal : public compare<Ty> {
        lower_equal() : compare<Ty>() {}
        const bool __cdecl operator()(const Ty& right, const Ty& left) const { return right <= left; }
    };


    /*
    * namespace with values compare define
    */
    namespace comparevalues {
        template<typename Ty>
        datastruct::higher<Ty> higher;

        template<typename Ty>
        datastruct::lower<Ty> lower;

        template<typename Ty>
        datastruct::equals<Ty> equals;

        template<typename Ty>
        datastruct::higher_equal<Ty> higher_equal;

        template<typename Ty>
        datastruct::lower_equal<Ty> lower_equal;
    }

    namespace lambdavalues {

        //parameter passed as reference and const
        template<typename Ty>
        using lmbboolconst = bool(*)(const Ty&, const Ty&);

        //parameter passed as reference not const
        template<typename Ty>
        using lmbbool = bool(*)(Ty&, Ty&);
    }

}