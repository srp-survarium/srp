unsigned int __thiscall Scaleform::GFx::Sprite::GetBytesLoaded(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::MovieDefRootNode *RootNode; // eax

  RootNode = Scaleform::GFx::DisplayObjContainer::FindRootNode(this);
  if ( RootNode )
    return RootNode->BytesLoaded;
  else
    return 0;
}
