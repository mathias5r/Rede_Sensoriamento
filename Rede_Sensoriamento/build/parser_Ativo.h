#ifndef ASN1_PARSER_ATIVO_H
#define ASN1_PARSER_ATIVO_H

#include <asn1++/asn1++.h>

#include<Subscriber.h>
#include<Unsubscriber.h>
#include<Notify.h>
#include<Publish.h>
#include<Ativo.h>

class TSubscriber : public ASN1DataType<Subscriber_t> {
 public:
 private:
  ASN1Oid * m_hierarchy;
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
    m_hierarchy = new ASN1Oid(pkt->hierarchy);
  }
  virtual ~TSubscriber() {
    delete m_hierarchy;
  }
  TSubscriber & operator=(const TSubscriber & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_hierarchy;
    init();
    destroy = false;
    return *this;
}
  ASN1Oid & get_hierarchy_attr() { return *m_hierarchy;}
  string get_hierarchy() { return m_hierarchy->str();}
  void set_hierarchy(const string & arg) { *m_hierarchy = arg;}
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

class TUnsubscriber : public ASN1DataType<Unsubscriber_t> {
 public:
 private:
  ASN1Oid * m_hierarchy;
 public:
  TUnsubscriber() : ASN1DataType<Unsubscriber_t>(&asn_DEF_Unsubscriber) {
    init();
  }
  TUnsubscriber(Unsubscriber_t * ptr) : ASN1DataType<Unsubscriber_t>(&asn_DEF_Unsubscriber, ptr) {
    destroy = false;
    init();
  }
  TUnsubscriber(const TUnsubscriber & o) : ASN1DataType<Unsubscriber_t>(&asn_DEF_Unsubscriber, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_hierarchy = new ASN1Oid(pkt->hierarchy);
  }
  virtual ~TUnsubscriber() {
    delete m_hierarchy;
  }
  TUnsubscriber & operator=(const TUnsubscriber & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_hierarchy;
    init();
    destroy = false;
    return *this;
}
  ASN1Oid & get_hierarchy_attr() { return *m_hierarchy;}
  string get_hierarchy() { return m_hierarchy->str();}
  void set_hierarchy(const string & arg) { *m_hierarchy = arg;}
  class DerSerializer : public DERSerializer<Unsubscriber_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Unsubscriber_t>(&asn_DEF_Unsubscriber, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TUnsubscriber & pkt) {DERSerializer<Unsubscriber_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Unsubscriber_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Unsubscriber_t>(&asn_DEF_Unsubscriber, inp) {}
    ~DerDeserializer() {}
    TUnsubscriber * deserialize() {
      ASN1DataType<Unsubscriber> * p = DERDeserializer<Unsubscriber_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TUnsubscriber * scan() {
      ASN1DataType<Unsubscriber> * p = DERDeserializer<Unsubscriber_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TUnsubscriber * get_obj(ASN1DataType<Unsubscriber_t> * p) {
      TUnsubscriber * obj = new TUnsubscriber(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Unsubscriber_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Unsubscriber_t>(&asn_DEF_Unsubscriber, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TUnsubscriber & pkt) {XERSerializer<Unsubscriber_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Unsubscriber_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Unsubscriber_t>(&asn_DEF_Unsubscriber, inp) {}
    ~XerDeserializer() {}
    TUnsubscriber * deserialize() {
      ASN1DataType<Unsubscriber> * p = XERDeserializer<Unsubscriber_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TUnsubscriber * scan() {
      ASN1DataType<Unsubscriber> * p = XERDeserializer<Unsubscriber_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TUnsubscriber * get_obj(ASN1DataType<Unsubscriber_t> * p) {
      TUnsubscriber * obj = new TUnsubscriber(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TNotify : public ASN1DataType<Notify_t> {
 public:
 private:
  ASN1Oid * m_hierarchy;
  ASN1String * m_data;
 public:
  TNotify() : ASN1DataType<Notify_t>(&asn_DEF_Notify) {
    init();
  }
  TNotify(Notify_t * ptr) : ASN1DataType<Notify_t>(&asn_DEF_Notify, ptr) {
    destroy = false;
    init();
  }
  TNotify(const TNotify & o) : ASN1DataType<Notify_t>(&asn_DEF_Notify, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_hierarchy = new ASN1Oid(pkt->hierarchy);
    m_data = new ASN1String(pkt->data);
  }
  virtual ~TNotify() {
    delete m_hierarchy;
    delete m_data;
  }
  TNotify & operator=(const TNotify & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_hierarchy;
    delete m_data;
    init();
    destroy = false;
    return *this;
}
  ASN1Oid & get_hierarchy_attr() { return *m_hierarchy;}
  string get_hierarchy() { return m_hierarchy->str();}
  void set_hierarchy(const string & arg) { *m_hierarchy = arg;}
  string get_data() { return m_data->str();}
  void set_data(const string & arg) { *m_data = arg;}
  class DerSerializer : public DERSerializer<Notify_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Notify_t>(&asn_DEF_Notify, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TNotify & pkt) {DERSerializer<Notify_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Notify_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Notify_t>(&asn_DEF_Notify, inp) {}
    ~DerDeserializer() {}
    TNotify * deserialize() {
      ASN1DataType<Notify> * p = DERDeserializer<Notify_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TNotify * scan() {
      ASN1DataType<Notify> * p = DERDeserializer<Notify_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TNotify * get_obj(ASN1DataType<Notify_t> * p) {
      TNotify * obj = new TNotify(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Notify_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Notify_t>(&asn_DEF_Notify, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TNotify & pkt) {XERSerializer<Notify_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Notify_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Notify_t>(&asn_DEF_Notify, inp) {}
    ~XerDeserializer() {}
    TNotify * deserialize() {
      ASN1DataType<Notify> * p = XERDeserializer<Notify_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TNotify * scan() {
      ASN1DataType<Notify> * p = XERDeserializer<Notify_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TNotify * get_obj(ASN1DataType<Notify_t> * p) {
      TNotify * obj = new TNotify(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TPublish : public ASN1DataType<Publish_t> {
 public:
 private:
  ASN1Oid * m_hierarchy;
  ASN1String * m_data;
 public:
  TPublish() : ASN1DataType<Publish_t>(&asn_DEF_Publish) {
    init();
  }
  TPublish(Publish_t * ptr) : ASN1DataType<Publish_t>(&asn_DEF_Publish, ptr) {
    destroy = false;
    init();
  }
  TPublish(const TPublish & o) : ASN1DataType<Publish_t>(&asn_DEF_Publish, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_hierarchy = new ASN1Oid(pkt->hierarchy);
    m_data = new ASN1String(pkt->data);
  }
  virtual ~TPublish() {
    delete m_hierarchy;
    delete m_data;
  }
  TPublish & operator=(const TPublish & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_hierarchy;
    delete m_data;
    init();
    destroy = false;
    return *this;
}
  ASN1Oid & get_hierarchy_attr() { return *m_hierarchy;}
  string get_hierarchy() { return m_hierarchy->str();}
  void set_hierarchy(const string & arg) { *m_hierarchy = arg;}
  string get_data() { return m_data->str();}
  void set_data(const string & arg) { *m_data = arg;}
  class DerSerializer : public DERSerializer<Publish_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Publish_t>(&asn_DEF_Publish, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TPublish & pkt) {DERSerializer<Publish_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Publish_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Publish_t>(&asn_DEF_Publish, inp) {}
    ~DerDeserializer() {}
    TPublish * deserialize() {
      ASN1DataType<Publish> * p = DERDeserializer<Publish_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPublish * scan() {
      ASN1DataType<Publish> * p = DERDeserializer<Publish_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPublish * get_obj(ASN1DataType<Publish_t> * p) {
      TPublish * obj = new TPublish(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Publish_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Publish_t>(&asn_DEF_Publish, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TPublish & pkt) {XERSerializer<Publish_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Publish_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Publish_t>(&asn_DEF_Publish, inp) {}
    ~XerDeserializer() {}
    TPublish * deserialize() {
      ASN1DataType<Publish> * p = XERDeserializer<Publish_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPublish * scan() {
      ASN1DataType<Publish> * p = XERDeserializer<Publish_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPublish * get_obj(ASN1DataType<Publish_t> * p) {
      TPublish * obj = new TPublish(p->_get_data());
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
    void set_unsubscriber() { ptr->present = id_PR_unsubscriber; }
    void set_unsubscriber(const TUnsubscriber & arg) {
      ptr->present = id_PR_unsubscriber;
    }
    TUnsubscriber get_unsubscriber() {
      check(id_PR_unsubscriber);
      TUnsubscriber pld(&ptr->choice.unsubscriber);
      pld.set_destroy(false);
      return pld;
    }
    void set_publish() { ptr->present = id_PR_publish; }
    void set_publish(const TPublish & arg) {
      ptr->present = id_PR_publish;
    }
    TPublish get_publish() {
      check(id_PR_publish);
      TPublish pld(&ptr->choice.publish);
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
    void set_notify() { ptr->present = id_PR_notify; }
    void set_notify(const TNotify & arg) {
      ptr->present = id_PR_notify;
    }
    TNotify get_notify() {
      check(id_PR_notify);
      TNotify pld(&ptr->choice.notify);
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
  Choice_id & get_id() { return *m_id;}
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
