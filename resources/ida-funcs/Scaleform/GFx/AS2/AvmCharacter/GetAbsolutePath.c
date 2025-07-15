const char *__thiscall Scaleform::GFx::AS2::AvmCharacter::GetAbsolutePath(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::String *ppath)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  Scaleform::GFx::DisplayObject *pParent; // ecx
  Scaleform::String *v5; // esi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS2::AvmCharacter *v8; // eax
  int v9; // eax
  Scaleform::String *v10; // esi
  int v1; // [esp+8h] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+Ch] [ebp-Ch] BYREF

  pDispObj = this->pDispObj;
  pParent = pDispObj->pParent;
  if ( pParent )
  {
    v5 = ppath;
    Scaleform::GFx::DisplayObject::GetAbsolutePath(pParent, ppath);
    Scaleform::String::AppendString(
      v5,
      (char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
      0xFFFFFFFF);
    Scaleform::GFx::DisplayObject::GetName(this->pDispObj, (Scaleform::GFx::ASString *)&ppath);
    Scaleform::String::AppendString(v5, (char *)ppath->pData, 0xFFFFFFFF);
    v6 = (Scaleform::GFx::ASStringNode *)ppath;
    --ppath[3].HeapTypeBits;
    if ( !v6->RefCount )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      return (const char *)((v5->HeapTypeBits & 0xFFFFFFFC) + 8);
    }
    return (const char *)((v5->HeapTypeBits & 0xFFFFFFFC) + 8);
  }
  if ( (pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    v5 = ppath;
    Scaleform::String::Clear(ppath);
    return (const char *)((v5->HeapTypeBits & 0xFFFFFFFC) + 8);
  }
  if ( this->GetObjectType(&this->Scaleform::GFx::AS2::ObjectInterface) == Object_Sprite )
    v8 = this;
  else
    v8 = 0;
  v9 = (int)v8[1].GetASEnvironment(v8 + 1);
  v10 = ppath;
  v1 = v9;
  result.Type = tStr;
  result.SinkData.pStr = ppath;
  Scaleform::Format<long>(&result, "_level{0}", &v1);
  return (const char *)((v10->HeapTypeBits & 0xFFFFFFFC) + 8);
}
