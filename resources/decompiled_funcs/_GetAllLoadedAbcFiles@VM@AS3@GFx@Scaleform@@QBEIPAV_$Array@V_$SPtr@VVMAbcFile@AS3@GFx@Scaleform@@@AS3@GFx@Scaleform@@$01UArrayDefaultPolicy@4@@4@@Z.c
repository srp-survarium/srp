int __thiscall Scaleform::GFx::AS3::VM::GetAllLoadedAbcFiles(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> *destArray)
{
  int v2; // ebp
  Scaleform::GFx::AS3::VMAbcFile *v3; // ebx
  unsigned int Size; // eax
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *Data; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v7; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM *v10; // [esp+4h] [ebp-8h]
  unsigned int n; // [esp+8h] [ebp-4h]

  v2 = 0;
  v10 = this;
  if ( !this->InDestructor )
  {
    n = this->VMAbcFilesWeak.Data.Size;
    if ( n )
    {
      while ( 1 )
      {
        v3 = this->VMAbcFilesWeak.Data.Data[v2];
        if ( v3 )
          v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
        Size = destArray->Data.Size;
        v5 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v5 >= destArray->Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)destArray,
              destArray,
              v5 + (v5 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
            &destArray->Data.Data[Size + 1],
            0xFFFFFFFF);
          if ( v5 < destArray->Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)destArray,
              destArray,
              v5);
        }
        Data = destArray->Data.Data;
        destArray->Data.Size = v5;
        v7 = &Data[v5 - 1];
        if ( v7 )
        {
          v7->pObject = v3;
          if ( !v3 )
            goto LABEL_19;
          v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v3 )
        {
          if ( ((unsigned __int8)v3 & 1) == 0 )
          {
            RefCount = v3->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              v3->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v3);
            }
          }
        }
LABEL_19:
        if ( ++v2 >= n )
          return v2;
        this = v10;
      }
    }
  }
  return v2;
}
