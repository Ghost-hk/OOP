class Event {
public:
    Event() = default;
    virtual void Execute() = 0;
};