//
// Created by jmmanos on 1/6/20.
//

#include "InfluxDBv2Client.h"

InfluxDBv2Client::InfluxDBv2Client(String host) {
    _host = host;
}

InfluxDBv2Client::InfluxDBv2Client(String host, String bucket, String org, String token) {
    _host = host;
    _bucket = bucket;
    _org = org;
    _token = token;
}

void InfluxDBv2Client::setBucket(String bucket) {
    _bucket = bucket;
}

void InfluxDBv2Client::setOrg(String org) {
    _org = org;
}

void InfluxDBv2Client::setToken(String token) {
    _token = token;
}

bool InfluxDBv2Client::write(Measurement measurement) {
    _httpClient.begin(_host + "/api/v2/write?org=" + _org + "&bucket=" + _bucket);
    _httpClient.addHeader("Content-Type", "text/plain");
    _httpClient.addHeader("Authorization", "Token " + _token);

    bool success = (_httpClient.POST(measurement.toString()) == HTTP_CODE_NO_CONTENT);

    _httpClient.end();

    return success;
}
