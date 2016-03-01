/* 
 * File:   CommsWifi.h
 * Author: Kevin
 *
 * Created on 1 mars 2016, 15:55
 */

#ifndef COMMSWIFI_H
#define COMMSWIFI_H

class CommsWifi {
  
  private:
    String apName;
    String apPassword;

  public:
    void connectToAP(String apName, String password);
    int getConnectionStatus();
    String get(String url, void* params);
    String post(String url, void* params);
    bool put(String url, void* params);
    bool del(String url, void* params);
};

#endif /* COMMSWIFI_H */