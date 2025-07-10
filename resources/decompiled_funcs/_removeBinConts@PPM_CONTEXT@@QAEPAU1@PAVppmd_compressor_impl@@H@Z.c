PPM_CONTEXT *__thiscall PPM_CONTEXT::removeBinConts(PPM_CONTEXT *this, ppmd_compressor_impl *impl, int Order)
{
  PPM_CONTEXT *Suffix; // eax
  int v5; // eax
  PPM_CONTEXT *v6; // ecx
  PPM_CONTEXT::STATE *Stats; // eax
  PPM_CONTEXT::STATE *v9; // edi

  if ( this->NumStats )
  {
    Stats = this->Stats;
    v9 = &Stats[this->NumStats];
    if ( v9 >= Stats )
    {
      do
      {
        if ( v9->Successor < (PPM_CONTEXT *)impl->m_allocator.UnitsStart || Order >= impl->MaxOrder )
          v9->Successor = 0;
        else
          v9->Successor = PPM_CONTEXT::removeBinConts(v9->Successor, impl, Order + 1);
        --v9;
      }
      while ( v9 >= this->Stats );
    }
  }
  else
  {
    if ( this->Stats < (PPM_CONTEXT::STATE *)impl->m_allocator.UnitsStart || Order >= impl->MaxOrder )
      this->Stats = 0;
    else
      this->Stats = (PPM_CONTEXT::STATE *)PPM_CONTEXT::removeBinConts((PPM_CONTEXT *)this->Stats, impl, Order + 1);
    if ( !this->Stats )
    {
      Suffix = this->Suffix;
      if ( !Suffix->NumStats || Suffix->Flags == 0xFF )
      {
        v5 = impl->m_allocator.Units2Indx[0];
        v6 = (PPM_CONTEXT *)impl->m_allocator.Indx2Units[v5];
        this->Stats = (PPM_CONTEXT::STATE *)impl->m_allocator.BList[v5].next;
        impl->m_allocator.BList[v5].next = (BLK_NODE *)this;
        *(_DWORD *)&this->NumStats = -1;
        this->Suffix = v6;
        ++impl->m_allocator.BList[v5].Stamp;
        return 0;
      }
    }
  }
  return this;
}
