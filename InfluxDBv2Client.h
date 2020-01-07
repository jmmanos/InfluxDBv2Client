//
// Created by jmmanos on 1/6/20.
//

#ifndef INFLUXDBV2CLIENT_INFLUXDBV2CLIENT_H
#define INFLUXDBV2CLIENT_INFLUXDBV2CLIENT_H

#include "Arduino.h"
#include <HTTPClient.h>
#include "Measurement.h"
#include <WiFi.h>

/**
 * Basic class to interact with InfluxDB v2
 */
class InfluxDBv2Client {
public:
    InfluxDBv2Client(String host);
    InfluxDBv2Client(String host, String bucket, String org, String token);

    void setBucket(String bucket);
    void setOrg(String org);
    void setToken(String token);

    bool write(Measurement measurement);

private:
    HTTPClient _httpClient;
    String _host;
    String _bucket;
    String _org;
    String _token;
};


#endif //INFLUXDBV2CLIENT_INFLUXDBV2CLIENT_H
