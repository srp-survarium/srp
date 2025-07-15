void __userpurge ppmd_allocator::FreeUnits(
        ppmd_allocator *this@<ecx>,
        int a2@<eax>,
        unsigned __int8 *ptr,
        unsigned int NU)
{
  int v4; // edx
  BLK_NODE *v5; // esi
  _DWORD *v6; // eax

  v4 = ptr[a2 + 345];
  v5 = (BLK_NODE *)*(unsigned __int8 *)(v4 + a2 + 308);
  v6 = (_DWORD *)(a2 + 8 * v4 + 4);
  this->BList[0].Stamp = v6[1];
  v6[1] = this;
  this->m_allocator = (vostok::memory::base_allocator *)-1;
  this->BList[0].next = v5;
  ++*v6;
}
