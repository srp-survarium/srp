void __thiscall Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(
        Scaleform::Render::Text::DocView::ImageSubstitutor *this,
        Scaleform::Render::Text::ImageDesc *pimgDesc)
{
  int v3; // ebp
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *Data; // eax
  int v5; // ebx
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  Scaleform::RefCountNTSImpl *pObject; // eax
  unsigned int i; // [esp+8h] [ebp-8h]
  unsigned int n; // [esp+Ch] [ebp-4h]

  v3 = 0;
  i = 0;
  n = this->Elements.Data.Size;
  if ( n )
  {
    do
    {
      Data = this->Elements.Data.Data;
      if ( this->Elements.Data.Data[v3].pImageDesc.pObject == pimgDesc )
      {
        v5 = 1;
        if ( this->Elements.Data.Size == 1 )
        {
          p_pObject = &Data->pImageDesc.pObject;
          do
          {
            if ( *p_pObject )
              Scaleform::RefCountNTSImpl::Release(*p_pObject);
            p_pObject -= 12;
            --v5;
          }
          while ( v5 );
          if ( (this->Elements.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
          {
            if ( this->Elements.Data.Data )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Elements.Data.Data);
              this->Elements.Data.Data = 0;
            }
            this->Elements.Data.Policy.Capacity = 0;
          }
          this->Elements.Data.Size = 0;
        }
        else
        {
          pObject = Data[v3].pImageDesc.pObject;
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
          memmove(
            (unsigned __int8 *)&this->Elements.Data.Data[v3],
            (unsigned __int8 *)&this->Elements.Data.Data[v3 + 1],
            48 * (this->Elements.Data.Size - i - 1));
          --this->Elements.Data.Size;
        }
      }
      else
      {
        ++i;
        ++v3;
      }
    }
    while ( i < n );
  }
}
