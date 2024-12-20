#ifndef TMS_HPP
#define TMS_HPP
#include <iostream>
#include <vector>
using namespace std;
class timingSlot
{
    private:
        /* data */
    public:
    int startHour;
    int endHour;
    TimeSlot(int sh, int eh): clinicHours(7, 21) {
        startHour = sh;
        endHour = eh;
        
    }
    bool isTimeValid(TimeSlot appointment, TimeSlot clinicHours) {
        // Check if appointment starts and ends within clinic hours
        if ((appointment.startHour > clinicHours.startHour || 
            (appointment.startHour == clinicHours.startHour && appointment.startMinute >= clinicHours.startMinute)) &&
            (appointment.endHour < clinicHours.endHour || 
            (appointment.endHour == clinicHours.endHour && appointment.endMinute <= clinicHours.endMinute))) {
            return true;
        }
        return false;
    }    
    bool checkAppointmentConflict(TimeSlot appointment, vector<TimeSlot> bookedAppointments) {
    for (TimeSlot booked : bookedAppointments) {
        // Check if times overlap
        if (!(appointment.endHour < booked.startHour || 
              (appointment.endHour == booked.startHour && appointment.endMinute <= booked.startMinute) ||
              (appointment.startHour > booked.endHour || 
              (appointment.startHour == booked.endHour && appointment.startMinute >= booked.endMinute)))) {
            return false; 
        }
    }
    return true;
}
};




#endif
