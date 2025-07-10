void __userpurge vostok::render::speedtree_forest::get_visible_tree_components(
        vostok::render::renderer_context *context@<eax>,
        const vostok::math::float3 *lod_reference_point@<ecx>,
        vostok::render::speedtree_forest *this,
        vostok::render::vector<vostok::render::speedtree_forest::tree_render_info> *sort_result,
        vostok::render::vector<vostok::render::speedtree_forest::tree_render_info> *out_tree_render_info_array)
{
  stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect> > *v5; // ebx
  vostok::render::speedtree_forest *v6; // ebp
  const SpeedTree::CArray<SpeedTree::CCore *,1> *m_pBaseTrees; // eax
  int v8; // esi
  SpeedTree::CCore *v9; // eax
  vostok::render::speedtree_tree_component_billboard *m_billboard_component; // eax
  vostok::render::culling::aab_rect *M_finish; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // eax
  char v15; // cl
  vostok::render::speedtree_forest::tree_render_info *v16; // eax
  vostok::render::lod_entry *lods; // edx
  vostok::render::speedtree_forest::tree_render_info *lod; // esi
  unsigned int v19; // ecx
  bool v20; // zf
  vostok::render::speedtree_forest::tree_render_info *v21; // ecx
  vostok::render::speedtree_tree_component *m_branch_component; // edx
  int v23; // eax
  int v24; // ebp
  int v25; // edi
  int v26; // eax
  char v27; // cl
  vostok::render::speedtree_forest::tree_render_info *v28; // eax
  vostok::render::speedtree_forest::tree_render_info *v29; // esi
  unsigned int v30; // edx
  vostok::render::lod_entry *v31; // ecx
  vostok::render::speedtree_forest::tree_render_info *v32; // ecx
  vostok::render::speedtree_tree_component *m_frond_component; // edx
  int v34; // eax
  int v35; // ebp
  int v36; // edi
  int v37; // eax
  char v38; // cl
  vostok::render::speedtree_forest::tree_render_info *v39; // eax
  vostok::render::speedtree_forest::tree_render_info *v40; // esi
  unsigned int v41; // edx
  vostok::render::lod_entry *v42; // ecx
  vostok::render::speedtree_forest::tree_render_info *v43; // ecx
  vostok::render::speedtree_tree_component *m_leafmesh_component; // edx
  int v45; // eax
  const SpeedTree::CArray<SpeedTree::SInstanceLod,1> *v46; // ecx
  int v47; // ebp
  SpeedTree::SInstanceLod *m_pData; // eax
  char m_nLeafCardLodIndex; // cl
  vostok::math::float2 v50; // rax
  unsigned int v51; // esi
  unsigned int v52; // edx
  vostok::render::lod_entry *v53; // ecx
  vostok::render::lod_entry *v54; // ecx
  vostok::render::culling::aab_rect *v55; // eax
  bool v56; // [esp+0h] [ebp-74h]
  const stlp_std::__true_type *v57; // [esp+0h] [ebp-74h]
  unsigned int v58; // [esp+4h] [ebp-70h]
  bool v59; // [esp+8h] [ebp-6Ch]
  vostok::render::speedtree_tree *base_tree; // [esp+10h] [ebp-64h]
  int base_tree_index; // [esp+14h] [ebp-60h]
  const SpeedTree::CArray<SpeedTree::SInstanceLod,1> *instance_lods; // [esp+18h] [ebp-5Ch]
  const SpeedTree::CArray<SpeedTree::SInstanceLod,1> *instance_lodsa; // [esp+18h] [ebp-5Ch]
  int v64; // [esp+1Ch] [ebp-58h]
  int v65; // [esp+1Ch] [ebp-58h]
  int v66; // [esp+1Ch] [ebp-58h]
  int v67; // [esp+1Ch] [ebp-58h]
  vostok::render::culling::aab_rect __x; // [esp+20h] [ebp-54h] BYREF
  vostok::render::culling::aab_rect v69; // [esp+30h] [ebp-44h] BYREF
  stlp_std::vector<vostok::render::speedtree_forest::tree_render_info,vostok::render::std_allocator<vostok::render::speedtree_forest::tree_render_info> > v70; // [esp+40h] [ebp-34h] BYREF
  vostok::render::speedtree_tree_component *v71; // [esp+4Ch] [ebp-28h]
  stlp_std::vector<vostok::render::speedtree_forest::tree_render_info,vostok::render::std_allocator<vostok::render::speedtree_forest::tree_render_info> > v72; // [esp+50h] [ebp-24h] BYREF
  vostok::render::speedtree_tree_component *v73; // [esp+5Ch] [ebp-18h]
  stlp_std::vector<vostok::render::speedtree_forest::tree_render_info,vostok::render::std_allocator<vostok::render::speedtree_forest::tree_render_info> > v74; // [esp+60h] [ebp-14h] BYREF
  vostok::render::speedtree_tree_component *v75; // [esp+6Ch] [ebp-8h]

  v5 = (stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect> > *)sort_result;
  v6 = this;
  vostok::render::speedtree_forest::cull_and_compute_lod(context, lod_reference_point, this, v56);
  m_pBaseTrees = this->m_visible_trees.m_pBaseTrees;
  v8 = 0;
  for ( base_tree_index = 0; v8 < (signed int)m_pBaseTrees->m_uiSize; base_tree_index = v8 )
  {
    v9 = m_pBaseTrees->m_pData[v8];
    if ( v9 )
      base_tree = (vostok::render::speedtree_tree *)&v9[-1].m_cWind.m_fDirectionChangeStartTime;
    else
      base_tree = 0;
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 262) )
    {
      m_billboard_component = base_tree->m_billboard_component;
      if ( m_billboard_component )
      {
        if ( m_billboard_component->m_render_geometry.geom.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          LODWORD(__x.max.y) = base_tree->m_billboard_component;
          M_finish = v5->_M_finish;
          memset(&__x, 0, 12);
          if ( M_finish == v5->_M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect>>::_M_insert_overflow(
              v5,
              M_finish,
              (stlp_std::priv::_Impl_vector<vostok::resources::creation_request,survarium::std_allocator<vostok::resources::creation_request> > *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
              &__x,
              v57,
              v58,
              v59);
          }
          else
          {
            if ( M_finish )
              *M_finish = __x;
            ++v5->_M_finish;
          }
        }
      }
    }
    v12 = SpeedTree::SForestCullResults::VisibleInstances(&v6->m_visible_trees, (const SpeedTree::CCore *)v8);
    instance_lods = (const SpeedTree::CArray<SpeedTree::SInstanceLod,1> *)v12;
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 263)
      && base_tree->m_abGeometryTypesPresent[0]
      && v12
      && *(int *)(v12 + 8) > 0 )
    {
      v13 = 0;
      v64 = *(_DWORD *)(v12 + 8);
      while ( 1 )
      {
        v14 = *(_DWORD *)(v12 + 4);
        v15 = *(_BYTE *)(v14 + v13 + 28);
        v16 = (vostok::render::speedtree_forest::tree_render_info *)(v13 + v14);
        if ( v15 > -1 )
        {
          lods = base_tree->m_lod_render_info[0].lods;
          lod = (vostok::render::speedtree_forest::tree_render_info *)v16->lod;
          v19 = s_speedtree_lod_index_value + v15;
          v20 = lods[v19].num_indices == 0;
          v21 = (vostok::render::speedtree_forest::tree_render_info *)&lods[v19];
          if ( !v20 )
          {
            m_branch_component = base_tree->m_branch_component;
            if ( m_branch_component )
            {
              if ( m_branch_component->m_render_geometry.geom.m_object
                && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
              {
                v70._M_impl._M_start = v21;
                v70._M_impl._M_end_of_storage._M_data = v16;
                v70._M_impl._M_finish = lod;
                v71 = m_branch_component;
                stlp_std::vector<vostok::render::speedtree_forest::tree_render_info,vostok::render::std_allocator<vostok::render::speedtree_forest::tree_render_info>>::push_back(
                  &v70,
                  (const vostok::render::speedtree_forest::tree_render_info *)v57);
              }
            }
          }
        }
        v13 += 32;
        if ( !--v64 )
          break;
        v12 = (int)instance_lods;
      }
      v8 = base_tree_index;
    }
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 264) )
    {
      if ( base_tree->m_abGeometryTypesPresent[1] )
      {
        v23 = SpeedTree::SForestCullResults::VisibleInstances(&this->m_visible_trees, (const SpeedTree::CCore *)v8);
        v24 = v23;
        if ( v23 )
        {
          if ( *(int *)(v23 + 8) > 0 )
          {
            v25 = 0;
            v65 = *(_DWORD *)(v23 + 8);
            do
            {
              v26 = *(_DWORD *)(v24 + 4);
              v27 = *(_BYTE *)(v26 + v25 + 29);
              v28 = (vostok::render::speedtree_forest::tree_render_info *)(v25 + v26);
              if ( v27 > -1 )
              {
                v29 = (vostok::render::speedtree_forest::tree_render_info *)v28->lod;
                v30 = s_speedtree_lod_index_value + v27;
                v31 = base_tree->m_lod_render_info[1].lods;
                v20 = v31[v30].num_indices == 0;
                v32 = (vostok::render::speedtree_forest::tree_render_info *)&v31[v30];
                if ( !v20 )
                {
                  m_frond_component = base_tree->m_frond_component;
                  if ( m_frond_component )
                  {
                    if ( m_frond_component->m_render_geometry.geom.m_object )
                    {
                      v5 = (stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect> > *)sort_result;
                      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
                      {
                        v72._M_impl._M_start = v32;
                        v72._M_impl._M_end_of_storage._M_data = v28;
                        v72._M_impl._M_finish = v29;
                        v73 = m_frond_component;
                        stlp_std::vector<vostok::render::speedtree_forest::tree_render_info,vostok::render::std_allocator<vostok::render::speedtree_forest::tree_render_info>>::push_back(
                          &v72,
                          (const vostok::render::speedtree_forest::tree_render_info *)v57);
                      }
                    }
                  }
                }
              }
              v25 += 32;
              --v65;
            }
            while ( v65 );
            v8 = base_tree_index;
          }
        }
      }
    }
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 266) )
    {
      if ( base_tree->m_abGeometryTypesPresent[3] )
      {
        v34 = SpeedTree::SForestCullResults::VisibleInstances(&this->m_visible_trees, (const SpeedTree::CCore *)v8);
        v35 = v34;
        if ( v34 )
        {
          if ( *(int *)(v34 + 8) > 0 )
          {
            v36 = 0;
            v66 = *(_DWORD *)(v34 + 8);
            do
            {
              v37 = *(_DWORD *)(v35 + 4);
              v38 = *(_BYTE *)(v37 + v36 + 31);
              v39 = (vostok::render::speedtree_forest::tree_render_info *)(v36 + v37);
              if ( v38 > -1 )
              {
                v40 = (vostok::render::speedtree_forest::tree_render_info *)v39->lod;
                v41 = s_speedtree_lod_index_value + v38;
                v42 = base_tree->m_lod_render_info[3].lods;
                v20 = v42[v41].num_indices == 0;
                v43 = (vostok::render::speedtree_forest::tree_render_info *)&v42[v41];
                if ( !v20 )
                {
                  m_leafmesh_component = base_tree->m_leafmesh_component;
                  if ( m_leafmesh_component )
                  {
                    if ( m_leafmesh_component->m_render_geometry.geom.m_object )
                    {
                      v5 = (stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect> > *)sort_result;
                      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
                      {
                        v74._M_impl._M_start = v43;
                        v74._M_impl._M_end_of_storage._M_data = v39;
                        v74._M_impl._M_finish = v40;
                        v75 = m_leafmesh_component;
                        stlp_std::vector<vostok::render::speedtree_forest::tree_render_info,vostok::render::std_allocator<vostok::render::speedtree_forest::tree_render_info>>::push_back(
                          &v74,
                          (const vostok::render::speedtree_forest::tree_render_info *)v57);
                      }
                    }
                  }
                }
              }
              v36 += 32;
              --v66;
            }
            while ( v66 );
            v8 = base_tree_index;
          }
        }
      }
    }
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 265) )
    {
      if ( base_tree->m_abGeometryTypesPresent[2] )
      {
        v45 = SpeedTree::SForestCullResults::VisibleInstances(&this->m_visible_trees, (const SpeedTree::CCore *)v8);
        v46 = (const SpeedTree::CArray<SpeedTree::SInstanceLod,1> *)v45;
        instance_lodsa = (const SpeedTree::CArray<SpeedTree::SInstanceLod,1> *)v45;
        if ( v45 )
        {
          if ( *(int *)(v45 + 8) > 0 )
          {
            v47 = 0;
            v67 = *(_DWORD *)(v45 + 8);
            while ( 1 )
            {
              m_pData = v46->m_pData;
              m_nLeafCardLodIndex = m_pData[v47].m_sLodSnapshot.m_nLeafCardLodIndex;
              LODWORD(v50.x) = &m_pData[v47];
              if ( m_nLeafCardLodIndex > -1 )
              {
                v51 = *(_DWORD *)LODWORD(v50.x);
                v52 = s_speedtree_lod_index_value + m_nLeafCardLodIndex;
                v53 = base_tree->m_lod_render_info[2].lods;
                v20 = v53[v52].num_indices == 0;
                v54 = &v53[v52];
                if ( !v20 )
                {
                  LODWORD(v50.y) = base_tree->m_leafcard_component;
                  if ( LODWORD(v50.y) )
                  {
                    if ( *(_DWORD *)(LODWORD(v50.y) + 8)
                      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
                    {
                      v69.max = v50;
                      v55 = v5->_M_finish;
                      v69.min = (vostok::math::float2)__PAIR64__(v51, (unsigned int)v54);
                      if ( v55 == v5->_M_end_of_storage._M_data )
                      {
                        stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect>>::_M_insert_overflow(
                          v5,
                          v55,
                          (stlp_std::priv::_Impl_vector<vostok::resources::creation_request,survarium::std_allocator<vostok::resources::creation_request> > *)&v69,
                          &v69,
                          v57,
                          v58,
                          v59);
                      }
                      else
                      {
                        if ( v55 )
                          *v55 = v69;
                        ++v5->_M_finish;
                      }
                    }
                  }
                }
              }
              ++v47;
              if ( !--v67 )
                break;
              v46 = instance_lodsa;
            }
            v8 = base_tree_index;
          }
        }
      }
    }
    v6 = this;
    m_pBaseTrees = this->m_visible_trees.m_pBaseTrees;
    ++v8;
  }
}
