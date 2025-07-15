PPM_CONTEXT *__thiscall PPM_CONTEXT::removeBinConts(PPM_CONTEXT *this, ppmd_compressor_impl *impl, int Order)
{
  PPM_CONTEXT *Suffix; // eax
  PPM_CONTEXT::STATE *Stats; // eax
  PPM_CONTEXT::STATE *v7; // esi
  unsigned int v8; // [esp+0h] [ebp-8h]

  if ( this->NumStats )
  {
    Stats = this->Stats;
    v7 = &Stats[this->NumStats];
    if ( v7 >= Stats )
    {
      do
      {
        if ( v7->Successor < (PPM_CONTEXT *)impl->m_allocator.UnitsStart || Order >= impl->MaxOrder )
          v7->Successor = 0;
        else
          v7->Successor = PPM_CONTEXT::removeBinConts(v7->Successor, impl, Order + 1);
        --v7;
      }
      while ( v7 >= this->Stats );
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
        ppmd_allocator::FreeUnits((ppmd_allocator *)this, (int)&impl->m_allocator, (unsigned __int8 *)1, v8);
        return 0;
      }
    }
  }
  return this;
}
