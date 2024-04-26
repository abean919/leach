//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/routing/leach/LeachPkts.msg.
//

#ifndef __INET_LEACHPKTS_M_H
#define __INET_LEACHPKTS_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class ScheduleEntry;
class LeachControlPkt;
class LeachDataPkt;
class LeachBSPkt;
class LeachAckPkt;
class LeachSchedulePkt;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address

// cplusplus {{
    #include <vector>
    #include "inet/common/INETDefs.h"
    #include "Leach.h"
    #include "inet/networklayer/contract/ipv4/Ipv4Address.h"
    using namespace std;
    using namespace inet;
    
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/routing/leach/LeachPkts.msg:47</tt> by opp_msgtool.
 * <pre>
 * enum LeachPktType
 * {
 *     CH = 1;
 *     ACK = 2;
 *     SCH = 3;
 *     DATA = 4;
 *     BS = 5;
 * }
 * </pre>
 */
enum LeachPktType {
    CH = 1,
    ACK = 2,
    SCH = 3,
    DATA = 4,
    BS = 5
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LeachPktType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LeachPktType& e) { int n; b->unpack(n); e = static_cast<LeachPktType>(n); }

/**
 * Class generated from <tt>inet/routing/leach/LeachPkts.msg:55</tt> by opp_msgtool.
 * <pre>
 * class ScheduleEntry extends cObject
 * {
 *     Ipv4Address nodeAddress;
 *     double TDMAdelay;
 * }
 * </pre>
 */
class INET_API ScheduleEntry : public ::omnetpp::cObject
{
  protected:
    Ipv4Address nodeAddress;
    double TDMAdelay = 0;

  private:
    void copy(const ScheduleEntry& other);

  protected:
    bool operator==(const ScheduleEntry&) = delete;

  public:
    ScheduleEntry();
    ScheduleEntry(const ScheduleEntry& other);
    virtual ~ScheduleEntry();
    ScheduleEntry& operator=(const ScheduleEntry& other);
    virtual ScheduleEntry *dup() const override {return new ScheduleEntry(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const Ipv4Address& getNodeAddress() const;
    virtual Ipv4Address& getNodeAddressForUpdate() { return const_cast<Ipv4Address&>(const_cast<ScheduleEntry*>(this)->getNodeAddress());}
    virtual void setNodeAddress(const Ipv4Address& nodeAddress);

    virtual double getTDMAdelay() const;
    virtual void setTDMAdelay(double TDMAdelay);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ScheduleEntry& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ScheduleEntry& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/leach/LeachPkts.msg:60</tt> by opp_msgtool.
 * <pre>
 * class LeachControlPkt extends FieldsChunk
 * {
 *     LeachPktType packetType = static_cast<LeachPktType>(-1);
 *     Ipv4Address srcAddress;
 *     string fingerprint;
 * 
 *     ScheduleEntry schedule[];
 * }
 * </pre>
 */
class INET_API LeachControlPkt : public ::inet::FieldsChunk
{
  protected:
    LeachPktType packetType = static_cast<LeachPktType>(-1);
    Ipv4Address srcAddress;
    ::omnetpp::opp_string fingerprint;
    ScheduleEntry *schedule = nullptr;
    size_t schedule_arraysize = 0;

  private:
    void copy(const LeachControlPkt& other);

  protected:
    bool operator==(const LeachControlPkt&) = delete;

  public:
    LeachControlPkt();
    LeachControlPkt(const LeachControlPkt& other);
    virtual ~LeachControlPkt();
    LeachControlPkt& operator=(const LeachControlPkt& other);
    virtual LeachControlPkt *dup() const override {return new LeachControlPkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual LeachPktType getPacketType() const;
    virtual void setPacketType(LeachPktType packetType);

    virtual const Ipv4Address& getSrcAddress() const;
    virtual Ipv4Address& getSrcAddressForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<LeachControlPkt*>(this)->getSrcAddress());}
    virtual void setSrcAddress(const Ipv4Address& srcAddress);

    virtual const char * getFingerprint() const;
    virtual void setFingerprint(const char * fingerprint);

    virtual void setScheduleArraySize(size_t size);
    virtual size_t getScheduleArraySize() const;
    virtual const ScheduleEntry& getSchedule(size_t k) const;
    virtual ScheduleEntry& getScheduleForUpdate(size_t k) { handleChange();return const_cast<ScheduleEntry&>(const_cast<LeachControlPkt*>(this)->getSchedule(k));}
    virtual void setSchedule(size_t k, const ScheduleEntry& schedule);
    virtual void insertSchedule(size_t k, const ScheduleEntry& schedule);
    [[deprecated]] void insertSchedule(const ScheduleEntry& schedule) {appendSchedule(schedule);}
    virtual void appendSchedule(const ScheduleEntry& schedule);
    virtual void eraseSchedule(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LeachControlPkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LeachControlPkt& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/leach/LeachPkts.msg:68</tt> by opp_msgtool.
 * <pre>
 * class LeachDataPkt extends LeachControlPkt
 * {
 *     double temperature;
 *     double humidity;
 * }
 * </pre>
 */
class INET_API LeachDataPkt : public ::inet::LeachControlPkt
{
  protected:
    double temperature = 0;
    double humidity = 0;

  private:
    void copy(const LeachDataPkt& other);

  protected:
    bool operator==(const LeachDataPkt&) = delete;

  public:
    LeachDataPkt();
    LeachDataPkt(const LeachDataPkt& other);
    virtual ~LeachDataPkt();
    LeachDataPkt& operator=(const LeachDataPkt& other);
    virtual LeachDataPkt *dup() const override {return new LeachDataPkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual double getTemperature() const;
    virtual void setTemperature(double temperature);

    virtual double getHumidity() const;
    virtual void setHumidity(double humidity);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LeachDataPkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LeachDataPkt& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/leach/LeachPkts.msg:73</tt> by opp_msgtool.
 * <pre>
 * class LeachBSPkt extends LeachControlPkt
 * {
 *     Ipv4Address CHAddr;
 * }
 * </pre>
 */
class INET_API LeachBSPkt : public ::inet::LeachControlPkt
{
  protected:
    Ipv4Address CHAddr;

  private:
    void copy(const LeachBSPkt& other);

  protected:
    bool operator==(const LeachBSPkt&) = delete;

  public:
    LeachBSPkt();
    LeachBSPkt(const LeachBSPkt& other);
    virtual ~LeachBSPkt();
    LeachBSPkt& operator=(const LeachBSPkt& other);
    virtual LeachBSPkt *dup() const override {return new LeachBSPkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const Ipv4Address& getCHAddr() const;
    virtual Ipv4Address& getCHAddrForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<LeachBSPkt*>(this)->getCHAddr());}
    virtual void setCHAddr(const Ipv4Address& CHAddr);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LeachBSPkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LeachBSPkt& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/leach/LeachPkts.msg:77</tt> by opp_msgtool.
 * <pre>
 * class LeachAckPkt extends LeachControlPkt
 * {
 * }
 * </pre>
 */
class INET_API LeachAckPkt : public ::inet::LeachControlPkt
{
  protected:

  private:
    void copy(const LeachAckPkt& other);

  protected:
    bool operator==(const LeachAckPkt&) = delete;

  public:
    LeachAckPkt();
    LeachAckPkt(const LeachAckPkt& other);
    virtual ~LeachAckPkt();
    LeachAckPkt& operator=(const LeachAckPkt& other);
    virtual LeachAckPkt *dup() const override {return new LeachAckPkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LeachAckPkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LeachAckPkt& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/leach/LeachPkts.msg:81</tt> by opp_msgtool.
 * <pre>
 * class LeachSchedulePkt extends LeachControlPkt
 * {
 * }
 * </pre>
 */
class INET_API LeachSchedulePkt : public ::inet::LeachControlPkt
{
  protected:

  private:
    void copy(const LeachSchedulePkt& other);

  protected:
    bool operator==(const LeachSchedulePkt&) = delete;

  public:
    LeachSchedulePkt();
    LeachSchedulePkt(const LeachSchedulePkt& other);
    virtual ~LeachSchedulePkt();
    LeachSchedulePkt& operator=(const LeachSchedulePkt& other);
    virtual LeachSchedulePkt *dup() const override {return new LeachSchedulePkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LeachSchedulePkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LeachSchedulePkt& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::ScheduleEntry *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::ScheduleEntry*>(ptr.get<cObject>()); }
template<> inline inet::LeachControlPkt *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::LeachControlPkt*>(ptr.get<cObject>()); }
template<> inline inet::LeachDataPkt *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::LeachDataPkt*>(ptr.get<cObject>()); }
template<> inline inet::LeachBSPkt *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::LeachBSPkt*>(ptr.get<cObject>()); }
template<> inline inet::LeachAckPkt *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::LeachAckPkt*>(ptr.get<cObject>()); }
template<> inline inet::LeachSchedulePkt *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::LeachSchedulePkt*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_LEACHPKTS_M_H

