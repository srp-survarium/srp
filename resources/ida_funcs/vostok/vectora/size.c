int __usercall vostok::vectora<survarium::scheduler::record>::size@<eax>(
        vostok::vectora<survarium::scheduler::record> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  return (a2[1] - *a2) / 56;
}


int __thiscall vostok::vectora<vostok::resources::request>::size(survarium::vector<vostok::resources::request> *this)
{
  return this->_M_impl._M_finish - this->_M_impl._M_start;
}
