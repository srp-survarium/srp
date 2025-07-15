void __thiscall Scaleform::GFx::AS2::Value::SetAsObjectInterface(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::ObjectInterface *pobj)
{
  unsigned __int32 v3; // eax
  Scaleform::GFx::AS2::ObjectInterface::ObjectType (__thiscall *GetObjectType)(Scaleform::GFx::AS2::ObjectInterface *); // edx
  Scaleform::GFx::DisplayObject *v5; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // esi

  v3 = pobj->GetObjectType(pobj) - 2;
  GetObjectType = pobj->GetObjectType;
  if ( v3 > 3 )
  {
    if ( (unsigned int)(GetObjectType(pobj) - 6) > 0x26 )
      Scaleform::GFx::AS2::Value::SetAsObject(this, 0);
    else
      Scaleform::GFx::AS2::Value::SetAsObject(this, (Scaleform::GFx::AS2::Object *)&pobj[-2].pProto);
  }
  else
  {
    if ( (unsigned int)(GetObjectType(pobj) - 2) <= 3 && (v5 = (Scaleform::GFx::DisplayObject *)pobj[1].__vftable) != 0 )
    {
      pObject = v5->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v5);
    }
    else
    {
      pObject = 0;
    }
    if ( this->T.Type != 7 || this->V.pCharHandle != pObject )
    {
      Scaleform::GFx::AS2::Value::DropRefs(this);
      this->T.Type = 7;
      this->NV.Int32Value = (int)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
  }
}
