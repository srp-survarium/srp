void __usercall vostok::mutable_buffer::operator+=(vostok::mutable_buffer *this@<ecx>, _DWORD *a2@<eax>)
{
  *a2 += this;
  a2[1] -= this;
}
