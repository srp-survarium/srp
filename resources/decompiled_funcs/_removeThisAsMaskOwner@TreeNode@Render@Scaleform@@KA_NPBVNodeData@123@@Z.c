char __cdecl Scaleform::Render::TreeNode::removeThisAsMaskOwner(const Scaleform::Render::TreeNode::NodeData *thisData)
{
  unsigned int State; // eax
  unsigned int v2; // esi
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  State = Scaleform::Render::StateBag::GetState(&thisData->States, State_UserEventHandler);
  v2 = State;
  if ( !State )
    return 0;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(
                   *(Scaleform::Render::ContextImpl::Entry **)(State + 4),
                   0x80u);
  *(_DWORD *)(*(_DWORD *)(v2 + 4) + 16) = 0;
  WritableData->Flags &= ~0x20u;
  Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&WritableData[8], State_FileOpener);
  return 1;
}
