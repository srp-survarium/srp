void __cdecl stlp_std::fill<void * *,void *>(void **__first, void **__last, void **__val)
{
  void **v3; // ecx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
    *v3++ = *__val;
}


void __usercall stlp_std::fill<survarium::account_list_item *,survarium::account_list_item>(
        survarium::account_list_item *__last@<eax>,
        survarium::account_list_item *__first,
        const survarium::account_list_item *__val)
{
  survarium::account_list_item *v3; // ebx
  int i; // eax
  survarium::account_list_item *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __val, sizeof(survarium::account_list_item));
  }
}


void __usercall stlp_std::fill<vostok::animation::EtKey *,vostok::animation::EtKey>(
        vostok::animation::EtKey *__last@<eax>,
        vostok::animation::EtKey *__first,
        const vostok::animation::EtKey *__val)
{
  vostok::animation::EtKey *v3; // ebx
  int i; // eax
  vostok::animation::EtKey *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __val, sizeof(vostok::animation::EtKey));
  }
}


void __usercall stlp_std::fill<survarium::quest_instance *,survarium::quest_instance>(
        survarium::quest_instance *__last@<eax>,
        survarium::quest_instance *__first,
        const survarium::quest_instance *__val)
{
  survarium::quest_instance *v3; // ebx
  int i; // eax
  survarium::quest_instance *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __val, sizeof(survarium::quest_instance));
  }
}


void __usercall stlp_std::fill<vostok::variant<32> *,vostok::variant<32>>(
        vostok::variant<32> *__last@<eax>,
        vostok::variant<32> *__first,
        const vostok::variant<32> *__val)
{
  vostok::variant<32> *v3; // ebx
  int v4; // ecx
  int i; // esi

  v3 = __first;
  v4 = 48;
  for ( i = __last - __first; i > 0; --i )
    vostok::variant<32>::operator=(v3++, __val, (vostok::variant<32> *)v4);
}
