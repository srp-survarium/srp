void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        unsigned int num,
        unsigned int *val)
{
  unsigned int v4; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  unsigned int *v9; // eax

  v4 = num;
  pHeap = this->Data.pHeap;
  v7 = num + this->Data.Size;
  if ( v7 >= this->Data.Size )
  {
    if ( v7 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v7 + (v7 >> 2));
  }
  else if ( v7 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v7);
  }
  this->Data.Size = v7;
  if ( index < v7 - num )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + num],
      (unsigned __int8 *)&this->Data.Data[index],
      4 * (v7 - index - num));
  if ( num )
  {
    v8 = index;
    do
    {
      v9 = &this->Data.Data[v8];
      if ( v9 )
        *v9 = *val;
      ++v8;
      --v4;
    }
    while ( v4 );
  }
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        signed int num,
        const long double *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // eax
  double *v11; // ecx
  int v12; // eax
  unsigned int v13; // ebx
  double *v14; // ecx
  unsigned int i; // [esp+18h] [ebp+8h]

  pHeap = this->Data.pHeap;
  v7 = num + this->Data.Size;
  if ( v7 >= this->Data.Size )
  {
    if ( v7 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v7 + (v7 >> 2));
  }
  else if ( v7 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v7);
  }
  this->Data.Size = v7;
  if ( index < v7 - num )
    memmove(
      (unsigned __int8 *)&this->Data.Data[num + index],
      (unsigned __int8 *)&this->Data.Data[index],
      8 * (v7 - index - num));
  v8 = 0;
  if ( num >= 4 )
  {
    v9 = ((unsigned int)(num - 4) >> 2) + 1;
    v10 = index;
    i = 4 * v9;
    do
    {
      v11 = &this->Data.Data[v10];
      if ( v11 )
        *v11 = *(double *)val;
      if ( &this->Data.Data[v10] != (long double *)-8 )
        this->Data.Data[v10 + 1] = *(double *)val;
      if ( &this->Data.Data[v10] != (long double *)-16 )
        this->Data.Data[v10 + 2] = *(double *)val;
      if ( &this->Data.Data[v10] != (long double *)-24 )
        this->Data.Data[v10 + 3] = *(double *)val;
      v10 += 4;
      --v9;
    }
    while ( v9 );
    v8 = i;
  }
  if ( v8 < num )
  {
    v12 = v8 + index;
    v13 = num - v8;
    do
    {
      v14 = &this->Data.Data[v12];
      if ( v14 )
        *v14 = *(double *)val;
      ++v12;
      --v13;
    }
    while ( v13 );
  }
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        unsigned int num,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int v4; // edi
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::Value *v7; // eax

  v4 = num;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    num + this->Data.Size);
  if ( index < this->Data.Size - num )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + num],
      (unsigned __int8 *)&this->Data.Data[index],
      16 * (this->Data.Size - index - num));
  if ( num )
  {
    v6 = index;
    do
    {
      v7 = &this->Data.Data[v6];
      if ( v7 )
      {
        *v7 = *val;
        if ( (val->Flags & 0x1F) > 9 )
        {
          if ( (val->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(val);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(val);
        }
      }
      ++v6;
      --v4;
    }
    while ( v4 );
  }
}
