int __usercall boost::function_base::has_trivial_copy_and_destroy@<eax>(
        boost::function_base *this@<ecx>,
        _DWORD *a2@<eax>)
{
  return *a2 & 1;
}
