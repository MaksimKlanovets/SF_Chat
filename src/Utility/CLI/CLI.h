class ICli {
  public:
    virtual char* getHelp();
    virtual bool tryCommand(char* command);
};

class Manager {
  public:
    void addCli(ICli* cli);
    void removeCli(ICli* cli);
};

