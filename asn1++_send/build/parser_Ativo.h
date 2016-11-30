#ifndef ASN1_PARSER_ATIVO_H
#define ASN1_PARSER_ATIVO_H

#include <asn1++/asn1++.h>

#include<Data.h>
#include<Registro.h>
#include<Connect.h>
#include<Ativo.h>

class TData : public ASN1DataType<Data_t> {
 public:
 private:
  ASN1String * m_info;
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
    m_info = new ASN1String(pkt->info);
    m_payload = new ASN1String(pkt->payload);
  }
  virtual ~TData() {
    delete m_info;
    delete m_payload;
  }
  TData & operator=(const TData & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_info;
    delete m_payload;
    init();
    destroy = false;
    return *this;
}
  string get_info() { return m_info->str();}
  void set_info(const string & arg) { *m_info = arg;}
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

class TRegistro : public ASN1DataType<Registro_t> {
 public:
 private:
  ASN1String * m_info;
  ASN1String * m_confirmation;
 public:
  TRegistro() : ASN1DataType<Registro_t>(&asn_DEF_Registro) {
    init();
  }
  TRegistro(Registro_t * ptr) : ASN1DataType<Registro_t>(&asn_DEF_Registro, ptr) {
    destroy = false;
    init();
  }
  TRegistro(const TRegistro & o) : ASN1DataType<Registro_t>(&asn_DEF_Registro, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_info = new ASN1String(pkt->info);
    m_confirmation = new ASN1String(pkt->confirmation);
  }
  virtual ~TRegistro() {
    delete m_info;
    delete m_confirmation;
  }
  TRegistro & operator=(const TRegistro & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_info;
    delete m_confirmation;
    init();
    destroy = false;
    return *this;
}
  string get_info() { return m_info->str();}
  void set_info(const string & arg) { *m_info = arg;}
  string get_confirmation() { return m_confirmation->str();}
  void set_confirmation(const string & arg) { *m_confirmation = arg;}
  class DerSerializer : public DERSerializer<Registro_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Registro_t>(&asn_DEF_Registro, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TRegistro & pkt) {DERSerializer<Registro_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Registro_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Registro_t>(&asn_DEF_Registro, inp) {}
    ~DerDeserializer() {}
    TRegistro * deserialize() {
      ASN1DataType<Registro> * p = DERDeserializer<Registro_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TRegistro * scan() {
      ASN1DataType<Registro> * p = DERDeserializer<Registro_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TRegistro * get_obj(ASN1DataType<Registro_t> * p) {
      TRegistro * obj = new TRegistro(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Registro_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Registro_t>(&asn_DEF_Registro, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TRegistro & pkt) {XERSerializer<Registro_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Registro_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Registro_t>(&asn_DEF_Registro, inp) {}
    ~XerDeserializer() {}
    TRegistro * deserialize() {
      ASN1DataType<Registro> * p = XERDeserializer<Registro_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TRegistro * scan() {
      ASN1DataType<Registro> * p = XERDeserializer<Registro_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TRegistro * get_obj(ASN1DataType<Registro_t> * p) {
      TRegistro * obj = new TRegistro(p->_get_data());
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
  ASN1String * m_deviceInfo;
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
    m_deviceInfo = new ASN1String(pkt->deviceInfo);
  }
  virtual ~TConnect() {
    delete m_deviceInfo;
  }
  TConnect & operator=(const TConnect & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_deviceInfo;
    init();
    destroy = false;
    return *this;
}
  bool get_deviceType() { return pkt->deviceType;}
  void set_deviceType(bool arg) { pkt->deviceType = arg;}
  string get_deviceInfo() { return m_deviceInfo->str();}
  void set_deviceInfo(const string & arg) { *m_deviceInfo = arg;}
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
    void set_registro() { ptr->present = id_PR_registro; }
    void set_registro(const TRegistro & arg) {
      ptr->present = id_PR_registro;
    }
    TRegistro get_registro() {
      check(id_PR_registro);
      TRegistro pld(&ptr->choice.registro);
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
