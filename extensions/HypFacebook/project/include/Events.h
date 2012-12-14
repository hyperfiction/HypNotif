#ifndef Events_H_
#define Events_H_

enum EventType{
  CONNECTION_OK,
  ON_REQUEST_COMPLETE,
  ON_REQUEST_FAILED,
  ON_DIALOG_SUCCESS
};

inline const char* EnumToString( EventType e ){
  switch( e ){
   
    case CONNECTION_OK:
      return "CONNECTION_OK";

    case ON_REQUEST_COMPLETE:
      return "ON_REQUEST_COMPLETE";

    case ON_REQUEST_FAILED:
      return "ON_REQUEST_FAILED";

    case ON_DIALOG_SUCCESS:
      return "ON_DIALOG_SUCCESS";

    default:
      return "Unknow";
  }    
}

#endif
