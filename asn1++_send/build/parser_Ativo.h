#ifndef ASN1_PARSER_ATIVO_H
#define ASN1_PARSER_ATIVO_H

#include <asn1++/asn1++.h>

#include<Info.h>
#include<Looking.h>
#include<Subscriber.h>
#include<Connect.h>
#include<Data.h>
#include<Ativo.h>

class TInfo : public ASN1DataType<Info_t> {
 public:
 private:
  ASN1String * m_sensors;
 public:
  TInfo() : ASN1DataType<Info_t>(&asn_DEF_Info) {
    init();
  }
  TInfo(Info_t * ptr) : ASN1DataType<Info_t>(&asn_DEF_Info, ptr) {
    destroy = false;
    init();
  }
  TInfo(const TInfo & o) : ASN1DataType<Info_t>(&asn_DEF_Info, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_sensors = new ASN1String(pkt->sensors);
  }
  virtual ~TInfo() {
    delete m_sensors;
  }
  TInfo & operator=(const TInfo & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_sensors;
    init();
    destroy = false;
    return *this;
}
  string get_sensors() { return m_sensors->str();}
  void set_sensors(const string & arg) { *m_sensors = arg;}
  class DerSerializer : public DERSerializer<Info_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Info_t>(&asn_DEF_Info, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TInfo & pkt) {DERSerializer<Info_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Info_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Info_t>(&asn_DEF_Info, inp) {}
    ~DerDeserializer() {}
    TInfo * deserialize() {
      ASN1DataType<Info> * p = DERDeserializer<Info_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TInfo * scan() {
      ASN1DataType<Info> * p = DERDeserializer<Info_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TInfo * get_obj(ASN1DataType<Info_t> * p) {
      TInfo * obj = new TInfo(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Info_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Info_t>(&asn_DEF_Info, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TInfo & pkt) {XERSerializer<Info_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Info_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Info_t>(&asn_DEF_Info, inp) {}
    ~XerDeserializer() {}
    TInfo * deserialize() {
      ASN1DataType<Info> * p = XERDeserializer<Info_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TInfo * scan() {
      ASN1DataType<Info> * p = XERDeserializer<Info_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TInfo * get_obj(ASN1DataType<Info_t> * p) {
      TInfo * obj = new TInfo(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TLooking : public ASN1DataType<Looking_t> {
 public:
 private:
  ASN1String * m_handshake;
 public:
  TLooking() : ASN1DataType<Looking_t>(&asn_DEF_Looking) {
    init();
  }
  TLooking(Looking_t * ptr) : ASN1DataType<Looking_t>(&asn_DEF_Looking, ptr) {
    destroy = false;
    init();
  }
  TLooking(const TLooking & o) : ASN1DataType<Looking_t>(&asn_DEF_Looking, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_handshake = new ASN1String(pkt->handshake);
  }
  virtual ~TLooking() {
    delete m_handshake;
  }
  TLooking & operator=(const TLooking & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_handshake;
    init();
    destroy = false;
    return *this;
}
  string get_handshake() { return m_handshake->str();}
  void set_handshake(const string & arg) { *m_handshake = arg;}
  class DerSerializer : public DERSerializer<Looking_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Looking_t>(&asn_DEF_Looking, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TLooking & pkt) {DERSerializer<Looking_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Looking_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Looking_t>(&asn_DEF_Looking, inp) {}
    ~DerDeserializer() {}
    TLooking * deserialize() {
      ASN1DataType<Looking> * p = DERDeserializer<Looking_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TLooking * scan() {
      ASN1DataType<Looking> * p = DERDeserializer<Looking_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TLooking * get_obj(ASN1DataType<Looking_t> * p) {
      TLooking * obj = new TLooking(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Looking_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Looking_t>(&asn_DEF_Looking, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TLooking & pkt) {XERSerializer<Looking_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Looking_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Looking_t>(&asn_DEF_Looking, inp) {}
    ~XerDeserializer() {}
    TLooking * deserialize() {
      ASN1DataType<Looking> * p = XERDeserializer<Looking_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TLooking * scan() {
      ASN1DataType<Looking> * p = XERDeserializer<Looking_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TLooking * get_obj(ASN1DataType<Looking_t> * p) {
      TLooking * obj = new TLooking(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TSubscriber : public ASN1DataType<Subscriber_t> {
 public:
 private:
  ASN1String * m_sensors;
 public:
  TSubscriber() : ASN1DataType<Subscriber_t>(&asn_DEF_Subscriber) {
    init();
  }
  TSubscriber(Subscriber_t * ptr) : ASN1DataType<Subscriber_t>(&asn_DEF_Subscriber, ptr) {
    destroy = false;
    init();
  }
  TSubscriber(const TSubscriber & o) : ASN1DataType<Subscriber_t>(&asn_DEF_Subscriber, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_sensors = new ASN1String(pkt->sensors);
  }
  virtual ~TSubscriber() {
    delete m_sensors;
  }
  TSubscriber & operator=(const TSubscriber & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_sensors;
    init();
    destroy = false;
    return *this;
}
  string get_sensors() { return m_sensors->str();}
  void set_sensors(const string & arg) { *m_sensors = arg;}
  class DerSerializer : public DERSerializer<Subscriber_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Subscriber_t>(&asn_DEF_Subscriber, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TSubscriber & pkt) {DERSerializer<Subscriber_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Subscriber_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Subscriber_t>(&asn_DEF_Subscriber, inp) {}
    ~DerDeserializer() {}
    TSubscriber * deserialize() {
      ASN1DataType<Subscriber> * p = DERDeserializer<Subscriber_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TSubscriber * scan() {
      ASN1DataType<Subscriber> * p = DERDeserializer<Subscriber_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TSubscriber * get_obj(ASN1DataType<Subscriber_t> * p) {
      TSubscriber * obj = new TSubscriber(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Subscriber_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Subscriber_t>(&asn_DEF_Subscriber, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TSubscriber & pkt) {XERSerializer<Subscriber_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Subscriber_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Subscriber_t>(&asn_DEF_Subscriber, inp) {}
    ~XerDeserializer() {}
    TSubscriber * deserialize() {
      ASN1DataType<Subscriber> * p = XERDeserializer<Subscriber_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TSubscriber * scan() {
      ASN1DataType<Subscriber> * p = XERDeserializer<Subscriber_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TSubscriber * get_obj(ASN1DataType<Subscriber_t> * p) {
      TSubscriber * obj = new TSubscriber(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TConnect : public ASN1DataType<Connect_t> {
 public:
 private:
 public:
  TConnect() : ASN1DataType<Connect_t>(&asn_DEF_Connect) {
    init();
  }
  TConnect(Connect_t * ptr) : ASN1DataType<Connect_t>(&asn_DEF_Connect, ptr) {
    destroy = false;
    init();
  }
  TConnect(const TConnect & o) : ASN1DataType<Connect_t>(&asn_DEF_Connect, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
  }
  virtual ~TConnect() {
  }
  TConnect & operator=(const TConnect & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    init();
    destroy = false;
    return *this;
}
  bool get_deviceType() { return pkt->deviceType;}
  void set_deviceType(bool arg) { pkt->deviceType = arg;}
  class DerSerializer : public DERSerializer<Connect_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Connect_t>(&asn_DEF_Connect, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TConnect & pkt) {DERSerializer<Connect_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Connect_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Connect_t>(&asn_DEF_Connect, inp) {}
    ~DerDeserializer() {}
    TConnect * deserialize() {
      ASN1DataType<Connect> * p = DERDeserializer<Connect_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TConnect * scan() {
      ASN1DataType<Connect> * p = DERDeserializer<Connect_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TConnect * get_obj(ASN1DataType<Connect_t> * p) {
      TConnect * obj = new TConnect(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Connect_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Connect_t>(&asn_DEF_Connect, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TConnect & pkt) {XERSerializer<Connect_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Connect_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Connect_t>(&asn_DEF_Connect, inp) {}
    ~XerDeserializer() {}
    TConnect * deserialize() {
      ASN1DataType<Connect> * p = XERDeserializer<Connect_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TConnect * scan() {
      ASN1DataType<Connect> * p = XERDeserializer<Connect_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TConnect * get_obj(ASN1DataType<Connect_t> * p) {
      TConnect * obj = new TConnect(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TData : public ASN1DataType<Data_t> {
 public:
 private:
  ASN1String * m_payload;
 public:
  TData() : ASN1DataType<Data_t>(&asn_DEF_Data) {
    init();
  }
  TData(Data_t * ptr) : ASN1DataType<Data_t>(&asn_DEF_Data, ptr) {
    destroy = false;
    init();
  }
  TData(const TData & o) : ASN1DataType<Data_t>(&asn_DEF_Data, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_payload = new ASN1String(pkt->payload);
  }
  virtual ~TData() {
    delete m_payload;
  }
  TData & operator=(const TData & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_payload;
    init();
    destroy = false;
    return *this;
}
  string get_payload() { return m_payload->str();}
  void set_payload(const string & arg) { *m_payload = arg;}
  class DerSerializer : public DERSerializer<Data_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Data_t>(&asn_DEF_Data, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TData & pkt) {DERSerializer<Data_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Data_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Data_t>(&asn_DEF_Data, inp) {}
    ~DerDeserializer() {}
    TData * deserialize() {
      ASN1DataType<Data> * p = DERDeserializer<Data_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TData * scan() {
      ASN1DataType<Data> * p = DERDeserializer<Data_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TData * get_obj(ASN1DataType<Data_t> * p) {
      TData * obj = new TData(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Data_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Data_t>(&asn_DEF_Data, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TData & pkt) {XERSerializer<Data_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Data_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Data_t>(&asn_DEF_Data, inp) {}
    ~XerDeserializer() {}
    TData * deserialize() {
      ASN1DataType<Data> * p = XERDeserializer<Data_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TData * scan() {
      ASN1DataType<Data> * p = XERDeserializer<Data_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TData * get_obj(ASN1DataType<Data_t> * p) {
      TData * obj = new TData(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TAtivo : public ASN1DataType<Ativo_t> {
 public:
  class Choice_id {
   private:
    typename Ativo_t::id * ptr;
    void check(id_PR attr) {
      if (ptr->present == id_PR_NOTHING) ptr->present = attr;
      if (ptr->present != attr) throw -1;
    }
   public:
    Choice_id(typename Ativo_t::id & rec) : ptr(&rec) {
    }
    Choice_id(typename Ativo_t::id & rec, bool reset) : ptr(&rec) {
      if (reset) ptr->present = id_PR_NOTHING;
    }
    ~Choice_id() {}
    id_PR get_choice() { return ptr->present;}
    void set_info() { ptr->present = id_PR_info; }
    void set_info(const TInfo & arg) {
      ptr->present = id_PR_info;
    }
    TInfo get_info() {
      check(id_PR_info);
      TInfo pld(&ptr->choice.info);
      pld.set_destroy(false);
      return pld;
    }
    void set_looking() { ptr->present = id_PR_looking; }
    void set_looking(const TLooking & arg) {
      ptr->present = id_PR_looking;
    }
    TLooking get_looking() {
      check(id_PR_looking);
      TLooking pld(&ptr->choice.looking);
      pld.set_destroy(false);
      return pld;
    }
    void set_subscriber() { ptr->present = id_PR_subscriber; }
    void set_subscriber(const TSubscriber & arg) {
      ptr->present = id_PR_subscriber;
    }
    TSubscriber get_subscriber() {
      check(id_PR_subscriber);
      TSubscriber pld(&ptr->choice.subscriber);
      pld.set_destroy(false);
      return pld;
    }
    void set_connect() { ptr->present = id_PR_connect; }
    void set_connect(const TConnect & arg) {
      ptr->present = id_PR_connect;
    }
    TConnect get_connect() {
      check(id_PR_connect);
      TConnect pld(&ptr->choice.connect);
      pld.set_destroy(false);
      return pld;
    }
    void set_data() { ptr->present = id_PR_data; }
    void set_data(const TData & arg) {
      ptr->present = id_PR_data;
    }
    TData get_data() {
      check(id_PR_data);
      TData pld(&ptr->choice.data);
      pld.set_destroy(false);
      return pld;
    }
  };

 private:
  Choice_id * m_id;
 public:
  TAtivo() : ASN1DataType<Ativo_t>(&asn_DEF_Ativo) {
    init();
  }
  TAtivo(Ativo_t * ptr) : ASN1DataType<Ativo_t>(&asn_DEF_Ativo, ptr) {
    destroy = false;
    init();
  }
  TAtivo(const TAtivo & o) : ASN1DataType<Ativo_t>(&asn_DEF_Ativo, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_id = new Choice_id(pkt->id, destroy);
  }
  virtual ~TAtivo() {
    delete m_id;
  }
  TAtivo & operator=(const TAtivo & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_id;
    init();
    destroy = false;
    return *this;
}
  long get_idDevice() { return pkt->idDevice;}
  void set_idDevice(long arg) { pkt->idDevice = arg;}
  long get_idBroker() { return pkt->idBroker;}
  void set_idBroker(long arg) { pkt->idBroker = arg;}
  Choice_id & get_id() { return *m_id;}
  long get_type() { return pkt->type;}
  void set_type(long arg) { pkt->type = arg;}
  class DerSerializer : public DERSerializer<Ativo_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Ativo_t>(&asn_DEF_Ativo, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TAtivo & pkt) {DERSerializer<Ativo_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Ativo_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Ativo_t>(&asn_DEF_Ativo, inp) {}
    ~DerDeserializer() {}
    TAtivo * deserialize() {
      ASN1DataType<Ativo> * p = DERDeserializer<Ativo_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TAtivo * scan() {
      ASN1DataType<Ativo> * p = DERDeserializer<Ativo_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TAtivo * get_obj(ASN1DataType<Ativo_t> * p) {
      TAtivo * obj = new TAtivo(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Ativo_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Ativo_t>(&asn_DEF_Ativo, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TAtivo & pkt) {XERSerializer<Ativo_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Ativo_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Ativo_t>(&asn_DEF_Ativo, inp) {}
    ~XerDeserializer() {}
    TAtivo * deserialize() {
      ASN1DataType<Ativo> * p = XERDeserializer<Ativo_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TAtivo * scan() {
      ASN1DataType<Ativo> * p = XERDeserializer<Ativo_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TAtivo * get_obj(ASN1DataType<Ativo_t> * p) {
      TAtivo * obj = new TAtivo(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

#endif
