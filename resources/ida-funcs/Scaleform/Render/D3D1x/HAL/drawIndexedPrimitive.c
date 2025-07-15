void __userpurge Scaleform::Render::D3D1x::HAL::drawIndexedPrimitive(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<esi>,
        unsigned int indexCount,
        unsigned int meshCount,
        unsigned int indexOffset,
        unsigned int vertexBaseIndex)
{
  (*(void (__stdcall **)(_DWORD, unsigned int, unsigned int, unsigned int))(**(_DWORD **)(a2 + 63956) + 48))(
    *(_DWORD *)(a2 + 63956),
    indexCount,
    indexOffset,
    vertexBaseIndex);
  *(_DWORD *)(a2 + 196) += meshCount;
  *(_DWORD *)(a2 + 200) += indexCount / 3;
  ++*(_DWORD *)(a2 + 192);
}
