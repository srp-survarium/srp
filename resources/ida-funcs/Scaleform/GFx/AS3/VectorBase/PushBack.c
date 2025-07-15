void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::PushBack(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::Value::V1U v5; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v8; // esi
  Scaleform::GFx::AS3::Value::V1U *v9; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-19h] BYREF
  Scaleform::GFx::AS3::Value *v; // [esp+8h] [ebp-18h]
  unsigned int i; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    i = 0;
    if ( argc )
    {
      v = argv;
      while ( 1 )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&argv, tr, v, &r)->Result )
          break;
        v5 = r.value.VS._1;
        pHeap = this->ValueA.Data.pHeap;
        p_ValueA = &this->ValueA;
        v8 = this->ValueA.Data.Size + 1;
        if ( v8 >= this->ValueA.Data.Size )
        {
          if ( v8 >= this->ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
              pHeap,
              v8 + (v8 >> 2));
        }
        else if ( v8 < this->ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
            pHeap,
            this->ValueA.Data.Size + 1);
        }
        v9 = (Scaleform::GFx::AS3::Value::V1U *)&p_ValueA->Data.Data[v8 - 1];
        this->ValueA.Data.Size = v8;
        if ( v9 )
          *v9 = v5;
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        ++v;
        if ( ++i >= argc )
          return;
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::PushBack(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  int v5; // ebp
  const Scaleform::GFx::AS3::ClassTraits::Traits *v6; // ebx
  const Scaleform::GFx::AS3::Value *i; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+8h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v5 = 0;
    if ( argc )
    {
      v6 = tr;
      for ( i = argv; ; ++i )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&argv, v6, i, &r)->Result )
          break;
        Scaleform::GFx::AS3::VectorBase<double>::PushBackUnsafe(this, &r);
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++v5 >= argc )
          return;
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBack(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  int v5; // ebp
  const Scaleform::GFx::AS3::ClassTraits::Traits *v6; // ebx
  const Scaleform::GFx::AS3::Value *i; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+8h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v5 = 0;
    if ( argc )
    {
      v6 = tr;
      for ( i = argv; ; ++i )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&argv, v6, i, &r)->Result )
          break;
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBackUnsafe(this, &r);
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++v5 >= argc )
          return;
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBack(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  const Scaleform::GFx::AS3::Value *j; // ebx
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v7; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-15h] BYREF
  unsigned int i; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS3::Value r; // [esp+Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    i = 0;
    if ( argc )
    {
      for ( j = argv; ; ++j )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&argv, tr, j, &r)->Result )
          break;
        VStr = r.value.VS._1.VStr;
        if ( r.value.VS._1.VInt )
          ++*(_DWORD *)(r.value.VS._1.VInt + 12);
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->ValueA.Data,
          this->ValueA.Data.pHeap,
          this->ValueA.Data.Size + 1);
        v7 = &this->ValueA.Data.Data[this->ValueA.Data.Size - 1];
        if ( &this->ValueA.Data.Data[this->ValueA.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)4 )
        {
          if ( VStr )
            ++VStr->RefCount;
          v7->pObject = VStr;
        }
        if ( VStr )
        {
          if ( VStr->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
        }
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++i >= argc )
          return;
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}
