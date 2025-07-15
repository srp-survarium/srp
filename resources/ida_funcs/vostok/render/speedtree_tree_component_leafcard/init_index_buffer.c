void __userpurge vostok::render::speedtree_tree_component_leafcard::init_index_buffer(
        vostok::render::vector<unsigned short> *out_indices@<eax>,
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *a2@<ecx>,
        vostok::render::speedtree_tree_component_leafcard *this,
        const SpeedTree::SLeafCards *lod,
        unsigned int num_accumulated_vertices)
{
  vostok::render::speedtree_tree_component_leafcard *v5; // esi
  bool v7; // cc
  unsigned __int16 *M_finish; // esi
  unsigned __int16 v9; // bp
  unsigned int v10; // eax
  char v11; // dl
  int *v12; // ecx
  unsigned int v13; // ecx
  int *v14; // eax
  int v15; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v17; // ecx
  unsigned __int8 *v18; // ebp
  unsigned int v19; // esi
  int v20; // eax
  unsigned __int8 *v21; // eax
  unsigned __int16 *v22; // ebx
  unsigned __int16 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int16 *v25; // eax
  unsigned __int16 *v26; // esi
  unsigned int v27; // eax
  char v28; // dl
  int *v29; // ecx
  unsigned int v30; // ecx
  int *v31; // eax
  int v32; // ecx
  vostok::render::grass_render_model *v33; // eax
  unsigned int v34; // ecx
  unsigned __int8 *v35; // ebp
  unsigned int v36; // esi
  int v37; // eax
  unsigned __int8 *v38; // eax
  unsigned __int16 *v39; // ebx
  unsigned __int16 *v40; // eax
  void *v41; // esi
  unsigned __int16 *v42; // eax
  unsigned __int16 *v43; // esi
  unsigned int v44; // eax
  char v45; // dl
  unsigned __int16 *v46; // ecx
  unsigned int v47; // ecx
  unsigned __int16 *v48; // eax
  int v49; // ecx
  vostok::render::grass_render_model *v50; // eax
  unsigned int v51; // ecx
  unsigned __int8 *v52; // ebp
  unsigned int v53; // esi
  int v54; // eax
  unsigned __int8 *v55; // eax
  unsigned __int16 *v56; // ebx
  unsigned __int16 *v57; // eax
  void *v58; // esi
  unsigned __int16 *v59; // eax
  unsigned __int16 *v60; // esi
  unsigned int v61; // eax
  char v62; // dl
  unsigned __int16 *v63; // ecx
  unsigned int v64; // ecx
  unsigned __int16 *v65; // eax
  int v66; // ecx
  vostok::render::grass_render_model *v67; // eax
  unsigned int v68; // ecx
  unsigned __int8 *v69; // ebp
  unsigned int v70; // esi
  int v71; // eax
  unsigned __int8 *v72; // eax
  unsigned __int16 *v73; // ebx
  unsigned __int16 *v74; // eax
  void *v75; // esi
  unsigned __int16 *v76; // eax
  unsigned __int16 *v77; // eax
  unsigned __int16 *v78; // eax
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *v79; // ecx
  bool v80; // [esp+0h] [ebp-2Ch]
  unsigned __int16 c_index; // [esp+10h] [ebp-1Ch]
  int card_index; // [esp+14h] [ebp-18h]
  int v83; // [esp+18h] [ebp-14h] BYREF
  int mg_index; // [esp+1Ch] [ebp-10h]
  int v85; // [esp+20h] [ebp-Ch] BYREF
  int v86; // [esp+24h] [ebp-8h] BYREF
  unsigned __int16 __x[2]; // [esp+28h] [ebp-4h] BYREF

  v5 = this;
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::reserve(
    a2,
    (unsigned int)out_indices,
    6 * (int)this->m_render_geometry.geom.m_object * (int)this->__vftable);
  v7 = (int)this->__vftable <= 0;
  mg_index = 0;
  if ( !v7 )
  {
    do
    {
      card_index = 0;
      if ( (int)v5->m_render_geometry.geom.m_object > 0 )
      {
        do
        {
          M_finish = out_indices->_M_impl._M_finish;
          v9 = (_WORD)lod + 4 * card_index;
          c_index = v9;
          if ( M_finish == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v10 = M_finish - out_indices->_M_impl._M_start;
            v11 = 1;
            v85 = 1;
            v83 = v10;
            if ( v10 == 0x7FFFFFFF )
              goto LABEL_100;
            v12 = &v83;
            if ( v10 <= 1 )
              v12 = &v85;
            v13 = v10 + *v12;
            v83 = v13;
            if ( v13 > 0x7FFFFFFF || v13 < v10 )
            {
              v13 = 0x7FFFFFFF;
              v83 = 0x7FFFFFFF;
            }
            v86 = v13;
            v85 = 1;
            v14 = &v85;
            if ( v13 )
              v14 = &v86;
            v15 = *v14;
            m_object = vostok::render::g_allocator.m_object;
            v17 = 2 * v15;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v17 )
              v11 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v11;
            if ( v17 )
              v18 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                         v17);
            else
              v18 = 0;
            v19 = (char *)M_finish - (char *)out_indices->_M_impl._M_start;
            if ( v19 )
            {
              memmove(v18, (unsigned __int8 *)out_indices->_M_impl._M_start, v19);
              v21 = (unsigned __int8 *)(v19 + v20);
            }
            else
            {
              v21 = v18;
            }
            *(_WORD *)v21 = c_index;
            v22 = (unsigned __int16 *)(v21 + 2);
            M_start = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
            }
            v25 = (unsigned __int16 *)&v18[2 * v83];
            out_indices->_M_impl._M_start = (unsigned __int16 *)v18;
            v9 = (_WORD)lod + 4 * card_index;
            out_indices->_M_impl._M_finish = v22;
            out_indices->_M_impl._M_end_of_storage._M_data = v25;
          }
          else
          {
            *M_finish = v9;
            ++out_indices->_M_impl._M_finish;
          }
          v26 = out_indices->_M_impl._M_finish;
          *(_DWORD *)__x = (unsigned __int16)(v9 + 1);
          if ( v26 == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v27 = v26 - out_indices->_M_impl._M_start;
            v28 = 1;
            v85 = 1;
            v86 = v27;
            if ( v27 == 0x7FFFFFFF )
              goto LABEL_100;
            v29 = &v86;
            if ( v27 <= 1 )
              v29 = &v85;
            v30 = v27 + *v29;
            v83 = v30;
            if ( v30 > 0x7FFFFFFF || v30 < v27 )
            {
              v30 = 0x7FFFFFFF;
              v83 = 0x7FFFFFFF;
            }
            v85 = v30;
            v86 = 1;
            v31 = &v86;
            if ( v30 )
              v31 = &v85;
            v32 = *v31;
            v33 = vostok::render::g_allocator.m_object;
            v34 = 2 * v32;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v34 )
              v28 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v28;
            if ( v34 )
              v35 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(v33->m_reconstruction_info_actuality_tick),
                                         v34);
            else
              v35 = 0;
            v36 = (char *)v26 - (char *)out_indices->_M_impl._M_start;
            if ( v36 )
            {
              memmove(v35, (unsigned __int8 *)out_indices->_M_impl._M_start, v36);
              v38 = (unsigned __int8 *)(v36 + v37);
            }
            else
            {
              v38 = v35;
            }
            *(_WORD *)v38 = __x[0];
            v39 = (unsigned __int16 *)(v38 + 2);
            v40 = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              v41 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v41, v40);
            }
            v42 = (unsigned __int16 *)&v35[2 * v83];
            out_indices->_M_impl._M_start = (unsigned __int16 *)v35;
            v9 = (_WORD)lod + 4 * card_index;
            out_indices->_M_impl._M_finish = v39;
            out_indices->_M_impl._M_end_of_storage._M_data = v42;
          }
          else
          {
            *v26 = v9 + 1;
            ++out_indices->_M_impl._M_finish;
          }
          v43 = out_indices->_M_impl._M_finish;
          v85 = (unsigned __int16)(v9 + 2);
          if ( v43 == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v44 = v43 - out_indices->_M_impl._M_start;
            v45 = 1;
            v86 = 1;
            *(_DWORD *)__x = v44;
            if ( v44 == 0x7FFFFFFF )
              goto LABEL_100;
            v46 = __x;
            if ( v44 <= 1 )
              v46 = (unsigned __int16 *)&v86;
            v47 = v44 + *(_DWORD *)v46;
            v83 = v47;
            if ( v47 > 0x7FFFFFFF || v47 < v44 )
            {
              v47 = 0x7FFFFFFF;
              v83 = 0x7FFFFFFF;
            }
            v86 = v47;
            *(_DWORD *)__x = 1;
            v48 = __x;
            if ( v47 )
              v48 = (unsigned __int16 *)&v86;
            v49 = *(_DWORD *)v48;
            v50 = vostok::render::g_allocator.m_object;
            v51 = 2 * v49;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v51 )
              v45 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v45;
            if ( v51 )
              v52 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(v50->m_reconstruction_info_actuality_tick),
                                         v51);
            else
              v52 = 0;
            v53 = (char *)v43 - (char *)out_indices->_M_impl._M_start;
            if ( v53 )
            {
              memmove(v52, (unsigned __int8 *)out_indices->_M_impl._M_start, v53);
              v55 = (unsigned __int8 *)(v53 + v54);
            }
            else
            {
              v55 = v52;
            }
            *(_WORD *)v55 = v85;
            v56 = (unsigned __int16 *)(v55 + 2);
            v57 = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              v58 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v58, v57);
            }
            v59 = (unsigned __int16 *)&v52[2 * v83];
            out_indices->_M_impl._M_start = (unsigned __int16 *)v52;
            v9 = (_WORD)lod + 4 * card_index;
            out_indices->_M_impl._M_finish = v56;
            out_indices->_M_impl._M_end_of_storage._M_data = v59;
          }
          else
          {
            *v43 = v9 + 2;
            ++out_indices->_M_impl._M_finish;
          }
          v60 = out_indices->_M_impl._M_finish;
          if ( v60 == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v61 = v60 - out_indices->_M_impl._M_start;
            v62 = 1;
            v86 = 1;
            *(_DWORD *)__x = v61;
            if ( v61 == 0x7FFFFFFF )
LABEL_100:
              stlp_std::__stl_throw_length_error("vector");
            v63 = __x;
            if ( v61 <= 1 )
              v63 = (unsigned __int16 *)&v86;
            v64 = v61 + *(_DWORD *)v63;
            v83 = v64;
            if ( v64 > 0x7FFFFFFF || v64 < v61 )
            {
              v64 = 0x7FFFFFFF;
              v83 = 0x7FFFFFFF;
            }
            v86 = v64;
            *(_DWORD *)__x = 1;
            v65 = __x;
            if ( v64 )
              v65 = (unsigned __int16 *)&v86;
            v66 = *(_DWORD *)v65;
            v67 = vostok::render::g_allocator.m_object;
            v68 = 2 * v66;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v68 )
              v62 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v62;
            if ( v68 )
              v69 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(v67->m_reconstruction_info_actuality_tick),
                                         v68);
            else
              v69 = 0;
            v70 = (char *)v60 - (char *)out_indices->_M_impl._M_start;
            if ( v70 )
            {
              memmove(v69, (unsigned __int8 *)out_indices->_M_impl._M_start, v70);
              v72 = (unsigned __int8 *)(v70 + v71);
            }
            else
            {
              v72 = v69;
            }
            *(_WORD *)v72 = c_index;
            v73 = (unsigned __int16 *)(v72 + 2);
            v74 = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              v75 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v75, v74);
            }
            v76 = (unsigned __int16 *)&v69[2 * v83];
            out_indices->_M_impl._M_start = (unsigned __int16 *)v69;
            v9 = (_WORD)lod + 4 * card_index;
            out_indices->_M_impl._M_finish = v73;
            out_indices->_M_impl._M_end_of_storage._M_data = v76;
          }
          else
          {
            *v60 = v9;
            ++out_indices->_M_impl._M_finish;
          }
          v77 = out_indices->_M_impl._M_finish;
          *(_DWORD *)__x = (unsigned __int16)(v9 + 2);
          if ( v77 == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
              (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)__x,
              (int)out_indices,
              v77,
              __x,
              (const stlp_std::__true_type *)1,
              1,
              v80);
          }
          else
          {
            *v77 = v9 + 2;
            ++out_indices->_M_impl._M_finish;
          }
          v78 = out_indices->_M_impl._M_finish;
          v79 = (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)(unsigned __int16)(v9 + 3);
          *(_DWORD *)__x = v79;
          if ( v78 == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
              v79,
              (int)out_indices,
              v78,
              __x,
              (const stlp_std::__true_type *)1,
              1,
              v80);
          }
          else
          {
            *v78 = (unsigned __int16)v79;
            ++out_indices->_M_impl._M_finish;
          }
          ++card_index;
        }
        while ( card_index < (int)this->m_render_geometry.geom.m_object );
      }
      v5 = this;
      v7 = ++mg_index < (int)this->__vftable;
    }
    while ( v7 );
  }
}
