namespace datastruct {

    template<typename Ty>
    struct compare {
        virtual const bool operator()(const Ty& right, const Ty& left) const = 0;
    };

    template<typename Ty>
    struct higher : public compare<Ty> {
        const bool operator()(const Ty& right, const Ty& left) const { return right > left; }
    };

    template<typename Ty>
    struct less : public compare<Ty> {
        const bool operator()(const Ty& right, const Ty& left) const { return right < left; }
    };

    template<typename Ty>
    struct equals : public compare<Ty> {
        const bool operator()(const Ty& right, const Ty& left) const { return right == left; }
    };

    template<typename Ty>
    struct higher_equal : public compare<Ty> {

        const bool operator()(const Ty& right, const Ty& left) const { return right >= left; }
    };

    template<typename Ty>
    struct less_equal : public compare<Ty> {
        const bool operator()(const Ty& right, const Ty& left) const { return right <= left; }
    };

}