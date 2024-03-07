class cipher
{
    public:
        cipher();
        std::string returnWord();
        std::string returnKey();
        std::string returnFullKey();
        std::string returnDecodedWord();
        void askForInput();
        void calcFullKey();
        int getAlphaNumberValue(char);
        void encode();
        void decode();
};