char __thiscall Scaleform::GFx::AS2::MovieClipObject::ActsAsButton(Scaleform::GFx::AS2::MovieClipObject *this)
{
  Scaleform::GFx::AS2::MovieClipObject *v1; // esi
  Scaleform::GFx::AS2::MovieClipObject *i; // edi

  v1 = this;
  if ( !this->ButtonEventMask )
  {
    while ( 2 )
    {
      if ( !v1->HasButtonHandlers )
      {
        for ( i = (Scaleform::GFx::AS2::MovieClipObject *)v1->pProto.pObject;
              ;
              i = (Scaleform::GFx::AS2::MovieClipObject *)i->pProto.pObject )
        {
          if ( !i )
            return 0;
          if ( v1->pProto.pObject->GetObjectType(&v1->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface) == Object_MovieClipObject )
            break;
        }
        v1 = i;
        if ( !i->ButtonEventMask )
          continue;
      }
      break;
    }
  }
  return 1;
}
