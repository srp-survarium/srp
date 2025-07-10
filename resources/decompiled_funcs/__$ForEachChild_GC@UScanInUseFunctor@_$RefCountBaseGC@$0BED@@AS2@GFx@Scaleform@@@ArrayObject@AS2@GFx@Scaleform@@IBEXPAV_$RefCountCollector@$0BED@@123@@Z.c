void __thiscall Scaleform::GFx::AS2::ArrayObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  unsigned int v4; // edi
  Scaleform::GFx::AS2::Value *v5; // ecx
  unsigned __int8 Type; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObjectValue; // eax
  unsigned int v8; // ecx
  unsigned int n; // [esp+10h] [ebp+4h]

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
  v4 = 0;
  n = this->Elements.Data.Size;
  if ( n )
  {
    do
    {
      v5 = this->Elements.Data.Data[v4];
      if ( v5 )
      {
        Type = v5->T.Type;
        if ( v5->T.Type == 8 )
        {
          Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
            &v5->V.FunctionValue,
            prcc);
        }
        else
        {
          if ( Type == 6 )
          {
            pObjectValue = v5->V.pObjectValue;
            if ( pObjectValue )
              goto LABEL_9;
          }
          if ( Type == 9 )
          {
            pObjectValue = v5->V.pObjectValue;
LABEL_9:
            v8 = ++pObjectValue->RefCount;
            if ( (v8 & 0x70000000) != 0 )
            {
              pObjectValue->RefCount = v8 & 0x8FFFFFFF;
              Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pObjectValue);
            }
          }
        }
      }
      ++v4;
    }
    while ( v4 < n );
  }
}
