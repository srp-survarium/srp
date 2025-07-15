unsigned int __thiscall Scaleform::Render::ShapeMeshProvider::GetFillCount(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int drawLayer,
        unsigned int meshGenFlags)
{
  return *((_DWORD *)&this->hKeySet.pManager.Value->KeySetLock.cs.DebugInfo + 5 * drawLayer);
}
