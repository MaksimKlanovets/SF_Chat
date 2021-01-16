enum EChannelType {
  Direct,
  Public,
};

struct Message
{
  const int from;
  const char* text;
};

struct Channel
{
  const EChannelType type;
  // TODO: использовать список
  const Message messages;
};


/**
 * Тут хранятся сообщения
 */
class MessagesStore {
  private:
    // TODO: использовать список
    const Channel messages;
};
