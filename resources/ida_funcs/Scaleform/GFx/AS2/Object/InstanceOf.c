char __thiscall Scaleform::GFx::AS2::Object::InstanceOf(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::AS2::Object *prototype,
        bool inclInterfaces)
{
  const Scaleform::GFx::AS2::Object *pObject; // esi

  pObject = (Scaleform::GFx::AS2::Object *)((char *)this - 16);
  if ( this != (Scaleform::GFx::AS2::Object *)16 )
  {
    do
    {
      if ( inclInterfaces )
      {
        if ( pObject->DoesImplement((Scaleform::GFx::AS2::Object *)pObject, penv, prototype) )
          return 1;
      }
      else if ( pObject == prototype )
      {
        return 1;
      }
      pObject = pObject->pProto.pObject;
    }
    while ( pObject );
  }
  return 0;
}
