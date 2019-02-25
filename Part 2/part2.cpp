int main() {
    typedef ADD<EXP<VAR, LIT<2>, <SUB<MULT<LIT<2>,VAR>, LIT<3>>> POLY;
    POLY p;
    
    return 0;
}