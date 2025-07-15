void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Append(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        const Scaleform::GFx::AS3::VectorBase<unsigned long> *other)
{
  unsigned int v4; // ebx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  unsigned int v7; // esi
  Scaleform::GFx::AS3::VectorBase<unsigned long>_vtbl **v8; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-1h] BYREF
  const Scaleform::GFx::AS3::VectorBase<unsigned long> *othera; // [esp+Ch] [ebp+4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v4 = 0;
    if ( other->ValueA.Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = p_ValueA[1].Data;
        v7 = p_ValueA->Size + 1;
        othera = (const Scaleform::GFx::AS3::VectorBase<unsigned long> *)&other->ValueA.Data.Data[v4];
        if ( v7 >= p_ValueA->Size )
        {
          if ( v7 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              Data,
              v7 + (v7 >> 2));
        }
        else if ( v7 < p_ValueA->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            Data,
            v7);
        }
        v8 = (Scaleform::GFx::AS3::VectorBase<unsigned long>_vtbl **)&p_ValueA->Data[v7 - 1];
        p_ValueA->Size = v7;
        if ( v8 )
          *v8 = othera->__vftable;
        ++v4;
      }
      while ( v4 < other->ValueA.Data.Size );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  unsigned int v4; // ebx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  unsigned int v7; // esi
  unsigned int **v8; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-1h] BYREF
  const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *arra; // [esp+Ch] [ebp+4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v4 = 0;
    if ( arr->Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = p_ValueA[1].Data;
        v7 = p_ValueA->Size + 1;
        arra = (const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)&arr->Data.Data[v4];
        if ( v7 >= p_ValueA->Size )
        {
          if ( v7 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              Data,
              v7 + (v7 >> 2));
        }
        else if ( v7 < p_ValueA->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            Data,
            v7);
        }
        v8 = (unsigned int **)&p_ValueA->Data[v7 - 1];
        p_ValueA->Size = v7;
        if ( v8 )
          *v8 = arra->Data.Data;
        ++v4;
      }
      while ( v4 < arr->Data.Size );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Append(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        const Scaleform::GFx::AS3::VectorBase<double> *other)
{
  const Scaleform::GFx::AS3::VectorBase<double> *v3; // eax
  unsigned int v4; // ebx
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  long double *Data; // ecx
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v7; // eax
  unsigned int v8; // esi
  double *v9; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-5h] BYREF
  double *v11; // [esp+14h] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = other;
    v4 = 0;
    if ( other->ValueA.Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = v3->ValueA.Data.Data;
        v7 = p_ValueA[1].Data;
        v8 = p_ValueA->Size + 1;
        v11 = &Data[v4];
        if ( v8 >= p_ValueA->Size )
        {
          if ( v8 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v7,
              v8 + (v8 >> 2));
        }
        else if ( v8 < p_ValueA->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            v7,
            v8);
        }
        v9 = (double *)&p_ValueA->Data[v8 - 1];
        p_ValueA->Size = v8;
        if ( v9 )
          *v9 = *v11;
        v3 = other;
        ++v4;
      }
      while ( v4 < other->ValueA.Data.Size );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Append(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        const Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  const Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *v3; // eax
  unsigned int v4; // ebx
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  long double *Data; // ecx
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v7; // eax
  unsigned int v8; // esi
  double *v9; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-5h] BYREF
  double *v11; // [esp+14h] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = arr;
    v4 = 0;
    if ( arr->Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = v3->Data.Data;
        v7 = p_ValueA[1].Data;
        v8 = p_ValueA->Size + 1;
        v11 = &Data[v4];
        if ( v8 >= p_ValueA->Size )
        {
          if ( v8 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v7,
              v8 + (v8 >> 2));
        }
        else if ( v8 < p_ValueA->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            v7,
            v8);
        }
        v9 = (double *)&p_ValueA->Data[v8 - 1];
        p_ValueA->Size = v8;
        if ( v9 )
          *v9 = *v11;
        v3 = arr;
        ++v4;
      }
      while ( v4 < arr->Data.Size );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Append(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        const Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *other)
{
  const Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v3; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::AS3::Value *Data; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *v7; // edi
  Scaleform::Pair<double,unsigned long> *v8; // ebp
  unsigned int v9; // esi
  Scaleform::Pair<double,unsigned long> *v10; // ecx
  unsigned int *v11; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-9h] BYREF
  unsigned int v13; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = other;
    i = 0;
    if ( other->ValueA.Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      v13 = 0;
      do
      {
        Data = v3->ValueA.Data.Data;
        Size = p_ValueA->Size;
        v7 = &Data[v13 / 0x10];
        v8 = p_ValueA[1].Data;
        v9 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v9 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v8,
              v9 + (v9 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
            (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[Size + 1],
            0xFFFFFFFF);
          if ( v9 < p_ValueA->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v8,
              v9);
        }
        v10 = p_ValueA->Data;
        p_ValueA->Size = v9;
        v11 = (unsigned int *)&v10[v9 - 1];
        if ( v11 )
        {
          *v11 = v7->Flags;
          v11[1] = (unsigned int)v7->Bonus.pWeakProxy;
          v11[2] = v7->value.VS._1.VUInt;
          v11[3] = (unsigned int)v7->value.VS._2.VObj;
          if ( (v7->Flags & 0x1F) > 9 )
          {
            if ( (v7->Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(v7);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(v7);
          }
        }
        v3 = other;
        v13 += 16;
        ++i;
      }
      while ( i < other->ValueA.Data.Size );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Append(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::AS3::Value *Data; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *v7; // edi
  Scaleform::Pair<double,unsigned long> *v8; // ebp
  unsigned int v9; // esi
  Scaleform::Pair<double,unsigned long> *v10; // ecx
  unsigned int *v11; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-9h] BYREF
  unsigned int v13; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = arr;
    i = 0;
    if ( arr->Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      v13 = 0;
      do
      {
        Data = v3->Data.Data;
        Size = p_ValueA->Size;
        v7 = &Data[v13 / 0x10];
        v8 = p_ValueA[1].Data;
        v9 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v9 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v8,
              v9 + (v9 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
            (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[Size + 1],
            0xFFFFFFFF);
          if ( v9 < p_ValueA->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              v8,
              v9);
        }
        v10 = p_ValueA->Data;
        p_ValueA->Size = v9;
        v11 = (unsigned int *)&v10[v9 - 1];
        if ( v11 )
        {
          *v11 = v7->Flags;
          v11[1] = (unsigned int)v7->Bonus.pWeakProxy;
          v11[2] = v7->value.VS._1.VUInt;
          v11[3] = (unsigned int)v7->value.VS._2.VObj;
          if ( (v7->Flags & 0x1F) > 9 )
          {
            if ( (v7->Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::AddRefWeakRef(v7);
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(v7);
          }
        }
        v3 = arr;
        v13 += 16;
        ++i;
      }
      while ( i < arr->Data.Size );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Append(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        const Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *other)
{
  const Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *v3; // ecx
  unsigned int v4; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // ebx
  int v7; // ebp
  unsigned int Size; // eax
  unsigned int v9; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v10; // eax
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v11; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-5h] BYREF
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = other;
    v4 = 0;
    i = 0;
    if ( other->ValueA.Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = p_ValueA[1].Data;
        v7 = (int)&v3->ValueA.Data.Data[v4];
        Size = p_ValueA->Size;
        v9 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v9 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              Data,
              v9 + (v9 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::DestructArray(
            (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&p_ValueA->Data[Size + 1],
            0xFFFFFFFF);
          if ( v9 < p_ValueA->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              Data,
              v9);
        }
        v10 = p_ValueA->Data;
        p_ValueA->Size = v9;
        v11 = &v10[v9 - 1];
        if ( v11 )
        {
          if ( *(_DWORD *)v7 )
            ++*(_DWORD *)(*(_DWORD *)v7 + 12);
          *v11 = *(const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **)v7;
        }
        v3 = other;
        v4 = i + 1;
        i = v4;
      }
      while ( v4 < other->ValueA.Data.Size );
    }
  }
}
