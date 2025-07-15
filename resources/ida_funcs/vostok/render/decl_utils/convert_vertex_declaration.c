void __cdecl vostok::render::decl_utils::convert_vertex_declaration(
        const vostok::render::vector<_D3DVERTEXELEMENT9> *declIn,
        vostok::render::vector<D3D11_INPUT_ELEMENT_DESC> *declOut)
{
  const vostok::render::vector<_D3DVERTEXELEMENT9> *v2; // ebx
  signed int v3; // edi
  int v4; // ebp
  signed int v5; // esi
  _D3DVERTEXELEMENT9 *M_start; // edx
  int Usage; // ebx
  _D3DVERTEXELEMENT9 *v8; // ecx
  D3D11_INPUT_ELEMENT_DESC *v9; // eax
  int v10; // edx
  char *v11; // edx
  int v12; // edx
  int v13; // edx
  D3D11_INPUT_ELEMENT_DESC __x; // [esp+10h] [ebp-1Ch] BYREF

  v2 = declIn;
  v3 = declIn->_M_impl._M_finish - declIn->_M_impl._M_start - 1;
  v4 = 0;
  memset((void *)&__x, 0, sizeof(__x));
  stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::resize(
    v3,
    &declOut->_M_impl,
    &__x);
  v5 = 0;
  if ( v3 > 0 )
  {
    while ( 2 )
    {
      M_start = v2->_M_impl._M_start;
      Usage = v2->_M_impl._M_start[v5].Usage;
      v8 = &M_start[v5];
      v9 = &declOut->_M_impl._M_start[v4];
      v10 = 0;
      while ( vostok::render::decl_utils::VertexSemanticList[v10].m_dx9Semantic != Usage )
      {
        if ( ++v10 >= 10 )
        {
          v11 = 0;
          goto LABEL_8;
        }
      }
      v11 = (&off_9BB8AC)[2 * v10];
LABEL_8:
      v9->SemanticName = v11;
      v9->SemanticIndex = v8->UsageIndex;
      v12 = 0;
      while ( vostok::render::decl_utils::VertexFormatList[v12].m_dx9FMT != v8->Type )
      {
        if ( ++v12 >= 15 )
        {
          v13 = 0;
          goto LABEL_12;
        }
      }
      v13 = dword_9BB834[2 * v12];
LABEL_12:
      v9->Format = v13;
      v9->InputSlot = v8->Stream;
      v9->AlignedByteOffset = v8->Offset;
      ++v5;
      ++v4;
      v9->InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
      v9->InstanceDataStepRate = 0;
      if ( v5 < v3 )
      {
        v2 = declIn;
        continue;
      }
      break;
    }
  }
}
