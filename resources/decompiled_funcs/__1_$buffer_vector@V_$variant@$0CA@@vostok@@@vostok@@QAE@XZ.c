void __usercall vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(
        vostok::buffer_vector<vostok::variant<32> > *this@<ecx>,
        int a2@<esi>)
{
  vostok::buffer_vector<vostok::variant<32>>::destroy(
    *(vostok::variant<32> **)a2,
    (vostok::variant<32> *const *)(a2 + 4));
  *(_DWORD *)(a2 + 4) = *(_DWORD *)a2;
}
