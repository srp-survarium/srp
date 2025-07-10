unsigned int __cdecl Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::CalcHash<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
        const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *data)
{
  unsigned int Flags; // eax
  unsigned int v2; // esi
  Scaleform::GFx::AS3::Value v; // [esp+0h] [ebp-10h] BYREF

  Flags = data->First.Flags;
  v.Bonus.pWeakProxy = data->First.Bonus.pWeakProxy;
  v.value.VNumber = data->First.value.VNumber;
  v.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&data->First);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&data->First);
  }
  LOBYTE(data) = 0;
  v2 = Scaleform::GFx::AS3::Value::HashFunctor::operator()((Scaleform::GFx::AS3::Value::HashFunctor *)&data, &v);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      return v2;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  return v2;
}
