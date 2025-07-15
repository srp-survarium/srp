void __usercall ppmd_allocator::SpecialFreeUnit(ppmd_allocator *this@<ecx>, _DWORD *a2@<eax>)
{
  if ( this == (ppmd_allocator *)a2[123] )
  {
    this->m_allocator = (vostok::memory::base_allocator *)-1;
    a2[123] += 12;
  }
  else
  {
    this->BList[0].Stamp = a2[2];
    a2[2] = this;
    this->m_allocator = (vostok::memory::base_allocator *)-1;
    this->BList[0].next = (BLK_NODE *)1;
    ++a2[1];
  }
}
