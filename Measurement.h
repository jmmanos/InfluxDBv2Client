//
// Created by jmmanos on 1/7/20.
//

#ifndef INFLUXDBV2CLIENT_MEASUREMENT_H
#define INFLUXDBV2CLIENT_MEASUREMENT_H

/**
 * Class to store a measurement that gets converted to line protocol for InfluxDB ingestion.
 */
class Measurement {
public:
    Measurement(String name): _name(name) {}

    void addTag(String key, String value) {
        _tags += (_tags == "") ? (key + "=" + value) : ("," + key + "=" + value);
    }

    void addValue(String key, float value) {
        _values += (_values == "") ? (key + "=" + String(value)) : ("," + key + "=" + String(value));
    }

    void setTimestamp(long int seconds) {
        _timestamp = String(seconds) + "000000000";
    }

    String toString() const {
        String measurementString = _name;

        if (_tags != "") {
            measurementString += "," + _tags;
        }

        measurementString += " " + _values;

        if (_timestamp != "") {
            measurementString += " " + _timestamp;
        }

        return measurementString;
    }

private:
    String _name;
    String _tags;
    String _values;
    String _timestamp;
};


#endif //INFLUXDBV2CLIENT_MEASUREMENT_H
