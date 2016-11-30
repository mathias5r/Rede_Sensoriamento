#ifndef ASN1_PARSER_ATIVO_H
#define ASN1_PARSER_ATIVO_H

#include <asn1++/asn1++.h>

#include<Data.h>
#include<Iniciate.h>
#include<Ativo.h>

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

class TIniciate : public ASN1DataType<Iniciate_t> {
 public:
 private:
  ASN1String * m_atop;
  ASN1String * m_name;
 public:
  TIniciate() : ASN1DataType<Iniciate_t>(&asn_DEF_Iniciate) {
    init();
  }
  TIniciate(Iniciate_t * ptr) : ASN1DataType<Iniciate_t>(&asn_DEF_Iniciate, ptr) {
    destroy = false;
    init();
  }
  TIniciate(const TIniciate & o) : ASN1DataType<Iniciate_t>(&asn_DEF_Iniciate, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_atop = new ASN1String(pkt->atop);
    m_name = new ASN1String(pkt->name);
  }
  virtual ~TIniciate() {
    delete m_atop;
    delete m_name;
  }
  TIniciate & operator=(const TIniciate & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_atop;
    delete m_name;
    init();
    destroy = false;
    return *this;
}
  string get_atop() { return m_atop->str();}
  void set_atop(const string & arg) { *m_atop = arg;}
  long get_type() { return pkt->type;}
  void set_type(long arg) { pkt->type = arg;}
  string get_name() { return m_name->str();}
  void set_name(const string & arg) { *m_name = arg;}
  class DerSerializer : public DERSerializer<Iniciate_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Iniciate_t>(&asn_DEF_Iniciate, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TIniciate & pkt) {DERSerializer<Iniciate_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Iniciate_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Iniciate_t>(&asn_DEF_Iniciate, inp) {}
    ~DerDeserializer() {}
    TIniciate * deserialize() {
      ASN1DataType<Iniciate> * p = DERDeserializer<Iniciate_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TIniciate * scan() {
      ASN1DataType<Iniciate> * p = DERDeserializer<Iniciate_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TIniciate * get_obj(ASN1DataType<Iniciate_t> * p) {
      TIniciate * obj = new TIniciate(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Iniciate_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Iniciate_t>(&asn_DEF_Iniciate, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TIniciate & pkt) {XERSerializer<Iniciate_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Iniciate_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Iniciate_t>(&asn_DEF_Iniciate, inp) {}
    ~XerDeserializer() {}
    TIniciate * deserialize() {
      ASN1DataType<Iniciate> * p = XERDeserializer<Iniciate_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TIniciate * scan() {
      ASN1DataType<Iniciate> * p = XERDeserializer<Iniciate_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TIniciate * get_obj(ASN1DataType<Iniciate_t> * p) {
      TIniciate * obj = new TIniciate(p->_get_data());
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
    void set_iniciate() { ptr->present = id_PR_iniciate; }
    void set_iniciate(const TIniciate & arg) {
      ptr->present = id_PR_iniciate;
    }
    TIniciate get_iniciate() {
      check(id_PR_iniciate);
      TIniciate pld(&ptr->choice.iniciate);
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
