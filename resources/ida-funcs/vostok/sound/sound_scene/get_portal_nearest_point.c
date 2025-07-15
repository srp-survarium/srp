vostok::math::float3 *__thiscall vostok::sound::sound_scene::get_portal_nearest_point(
        vostok::sound::sound_scene *this,
        vostok::math::float3 *result,
        unsigned int portal_id,
        vostok::math::float3 segment_start,
        vostok::math::float3 segment_end)
{
  vostok::sound::closets_point_predicate v6; // [esp+64h] [ebp-6E4h]
  stlp_std::pair<float,vostok::math::float3> *i; // [esp+74h] [ebp-6D4h]
  vostok::math::float3 v8; // [esp+8Ch] [ebp-6BCh]
  float v9; // [esp+98h] [ebp-6B0h]
  vostok::math::float3 *v10; // [esp+B8h] [ebp-690h]
  float v11; // [esp+C0h] [ebp-688h]
  float v12; // [esp+C4h] [ebp-684h]
  vostok::math::float3 v13; // [esp+D4h] [ebp-674h]
  float v14; // [esp+E0h] [ebp-668h]
  vostok::math::float3 *v15; // [esp+F8h] [ebp-650h]
  float v16; // [esp+100h] [ebp-648h]
  float v17; // [esp+104h] [ebp-644h]
  vostok::math::float3 v18; // [esp+108h] [ebp-640h]
  float v19; // [esp+114h] [ebp-634h]
  vostok::math::float3 *v20; // [esp+12Ch] [ebp-61Ch]
  float v21; // [esp+134h] [ebp-614h]
  float v22; // [esp+138h] [ebp-610h]
  vostok::math::float3 v23; // [esp+13Ch] [ebp-60Ch]
  float v24; // [esp+148h] [ebp-600h]
  vostok::math::float3 *v25; // [esp+154h] [ebp-5F4h]
  float v26; // [esp+15Ch] [ebp-5ECh]
  float v27; // [esp+160h] [ebp-5E8h]
  vostok::math::float3 v28; // [esp+17Ch] [ebp-5CCh]
  float v29; // [esp+188h] [ebp-5C0h]
  vostok::math::float3 *v30; // [esp+194h] [ebp-5B4h]
  float v31; // [esp+19Ch] [ebp-5ACh]
  float v32; // [esp+1A0h] [ebp-5A8h]
  vostok::math::float3 v33; // [esp+1A4h] [ebp-5A4h]
  float v34; // [esp+1B0h] [ebp-598h]
  vostok::math::float3 *v35; // [esp+1BCh] [ebp-58Ch]
  float v36; // [esp+1C4h] [ebp-584h]
  float v37; // [esp+1C8h] [ebp-580h]
  vostok::math::float3 v38; // [esp+1CCh] [ebp-57Ch]
  float v39; // [esp+1D8h] [ebp-570h]
  vostok::math::float3 *v40; // [esp+1E4h] [ebp-564h]
  float v41; // [esp+1ECh] [ebp-55Ch]
  float v42; // [esp+1F0h] [ebp-558h]
  vostok::math::float3 v43; // [esp+1F4h] [ebp-554h]
  float v44; // [esp+200h] [ebp-548h]
  vostok::math::float3 *v45; // [esp+20Ch] [ebp-53Ch]
  float v46; // [esp+214h] [ebp-534h]
  float v47; // [esp+218h] [ebp-530h]
  vostok::math::float3 v48; // [esp+234h] [ebp-514h]
  float v49; // [esp+240h] [ebp-508h]
  vostok::math::float3 *v50; // [esp+24Ch] [ebp-4FCh]
  vostok::math::float3 v51; // [esp+250h] [ebp-4F8h]
  float v52; // [esp+25Ch] [ebp-4ECh]
  vostok::math::float3 *v53; // [esp+268h] [ebp-4E0h]
  vostok::math::float3 v54; // [esp+26Ch] [ebp-4DCh]
  float v55; // [esp+278h] [ebp-4D0h]
  vostok::math::float3 *v56; // [esp+284h] [ebp-4C4h]
  vostok::math::float3 v57; // [esp+288h] [ebp-4C0h]
  float v58; // [esp+294h] [ebp-4B4h]
  vostok::math::float3 *v59; // [esp+2A0h] [ebp-4A8h]
  vostok::math::float3 v60; // [esp+2A4h] [ebp-4A4h]
  float v61; // [esp+2B0h] [ebp-498h]
  vostok::math::float3 *v62; // [esp+2BCh] [ebp-48Ch]
  vostok::math::float3 v63; // [esp+2C0h] [ebp-488h]
  float v64; // [esp+2CCh] [ebp-47Ch]
  vostok::math::float3 *v65; // [esp+2D0h] [ebp-478h]
  vostok::math::float3 v66; // [esp+2D4h] [ebp-474h]
  float v67; // [esp+2E0h] [ebp-468h]
  vostok::math::float3 *v68; // [esp+2E4h] [ebp-464h]
  vostok::math::float3 v69; // [esp+2E8h] [ebp-460h]
  float v70; // [esp+2F4h] [ebp-454h]
  vostok::math::float3 *v71; // [esp+2F8h] [ebp-450h]
  vostok::math::float3 *v72; // [esp+2FCh] [ebp-44Ch]
  float v73; // [esp+300h] [ebp-448h]
  vostok::math::float3 *v74; // [esp+304h] [ebp-444h]
  vostok::vectora_allocator<void *> allocator; // [esp+30Ch] [ebp-43Ch] BYREF
  vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > v76; // [esp+310h] [ebp-438h] BYREF
  char v77; // [esp+317h] [ebp-431h]
  vostok::render::culling::portal_sector_structure *m_object; // [esp+318h] [ebp-430h]
  char v79; // [esp+31Fh] [ebp-429h]
  vostok::sound::closets_point_predicate v80; // [esp+320h] [ebp-428h]
  stlp_std::pair<float,vostok::math::float3> v81; // [esp+330h] [ebp-418h] BYREF
  SpeedTree::Vec3 v82; // [esp+340h] [ebp-408h] BYREF
  vostok::math::float3 v83; // [esp+34Ch] [ebp-3FCh] BYREF
  vostok::math::float3 v84; // [esp+358h] [ebp-3F0h] BYREF
  stlp_std::pair<float,vostok::math::float3> v85; // [esp+364h] [ebp-3E4h] BYREF
  SpeedTree::Vec3 v86; // [esp+374h] [ebp-3D4h] BYREF
  vostok::math::float3 v87; // [esp+380h] [ebp-3C8h] BYREF
  vostok::math::float3 v88; // [esp+38Ch] [ebp-3BCh] BYREF
  stlp_std::pair<float,vostok::math::float3> v89; // [esp+398h] [ebp-3B0h] BYREF
  SpeedTree::Vec3 v90; // [esp+3A8h] [ebp-3A0h] BYREF
  vostok::math::float3 v91; // [esp+3B4h] [ebp-394h] BYREF
  vostok::math::float3 v92; // [esp+3C0h] [ebp-388h] BYREF
  stlp_std::pair<float,vostok::math::float3> v93; // [esp+3CCh] [ebp-37Ch] BYREF
  SpeedTree::Vec3 v94; // [esp+3DCh] [ebp-36Ch] BYREF
  vostok::math::float3 v95; // [esp+3E8h] [ebp-360h] BYREF
  vostok::math::float3 v96; // [esp+3F4h] [ebp-354h] BYREF
  float v97; // [esp+400h] [ebp-348h]
  float v98; // [esp+404h] [ebp-344h]
  float v99; // [esp+408h] [ebp-340h]
  float v100; // [esp+40Ch] [ebp-33Ch]
  float v101; // [esp+410h] [ebp-338h]
  float v102; // [esp+414h] [ebp-334h]
  stlp_std::pair<float,vostok::math::float3> v103; // [esp+418h] [ebp-330h] BYREF
  SpeedTree::Vec3 v104; // [esp+428h] [ebp-320h] BYREF
  vostok::math::float3 v105; // [esp+434h] [ebp-314h] BYREF
  vostok::math::float3 v106; // [esp+440h] [ebp-308h] BYREF
  stlp_std::pair<float,vostok::math::float3> v107; // [esp+44Ch] [ebp-2FCh] BYREF
  SpeedTree::Vec3 v108; // [esp+45Ch] [ebp-2ECh] BYREF
  vostok::math::float3 v109; // [esp+468h] [ebp-2E0h] BYREF
  vostok::math::float3 v110; // [esp+474h] [ebp-2D4h] BYREF
  stlp_std::pair<float,vostok::math::float3> v111; // [esp+480h] [ebp-2C8h] BYREF
  SpeedTree::Vec3 v112; // [esp+490h] [ebp-2B8h] BYREF
  vostok::math::float3 v113; // [esp+49Ch] [ebp-2ACh] BYREF
  vostok::math::float3 v114; // [esp+4A8h] [ebp-2A0h] BYREF
  stlp_std::pair<float,vostok::math::float3> v115; // [esp+4B4h] [ebp-294h] BYREF
  SpeedTree::Vec3 v116; // [esp+4C4h] [ebp-284h] BYREF
  vostok::math::float3 v117; // [esp+4D0h] [ebp-278h] BYREF
  vostok::math::float3 v118; // [esp+4DCh] [ebp-26Ch] BYREF
  float v119; // [esp+4E8h] [ebp-260h]
  float v120; // [esp+4ECh] [ebp-25Ch]
  float v121; // [esp+4F0h] [ebp-258h]
  float v122; // [esp+4F4h] [ebp-254h]
  float v123; // [esp+4F8h] [ebp-250h]
  float v124; // [esp+4FCh] [ebp-24Ch]
  stlp_std::pair<float,vostok::math::float3> v125; // [esp+500h] [ebp-248h] BYREF
  vostok::math::float3 v126; // [esp+510h] [ebp-238h] BYREF
  vostok::math::float3 v127; // [esp+51Ch] [ebp-22Ch] BYREF
  vostok::math::float3 v128; // [esp+528h] [ebp-220h] BYREF
  stlp_std::pair<float,vostok::math::float3> v129; // [esp+534h] [ebp-214h] BYREF
  vostok::math::float3 v130; // [esp+544h] [ebp-204h] BYREF
  vostok::math::float3 v131; // [esp+550h] [ebp-1F8h] BYREF
  vostok::math::float3 v132; // [esp+55Ch] [ebp-1ECh] BYREF
  stlp_std::pair<float,vostok::math::float3> v133; // [esp+568h] [ebp-1E0h] BYREF
  vostok::math::float3 v134; // [esp+578h] [ebp-1D0h] BYREF
  vostok::math::float3 v135; // [esp+584h] [ebp-1C4h] BYREF
  vostok::math::float3 v136; // [esp+590h] [ebp-1B8h] BYREF
  stlp_std::pair<float,vostok::math::float3> v137; // [esp+59Ch] [ebp-1ACh] BYREF
  vostok::math::float3 v138; // [esp+5ACh] [ebp-19Ch] BYREF
  vostok::math::float3 v139; // [esp+5B8h] [ebp-190h] BYREF
  vostok::math::float3 v140; // [esp+5C4h] [ebp-184h] BYREF
  vostok::math::float3 v141; // [esp+5D0h] [ebp-178h] BYREF
  vostok::math::float3 v142; // [esp+5DCh] [ebp-16Ch] BYREF
  stlp_std::pair<float,vostok::math::float3> v143; // [esp+5E8h] [ebp-160h] BYREF
  vostok::math::float3 v144; // [esp+5F8h] [ebp-150h] BYREF
  vostok::math::float3 v145; // [esp+604h] [ebp-144h] BYREF
  vostok::math::float3 v146; // [esp+610h] [ebp-138h] BYREF
  stlp_std::pair<float,vostok::math::float3> v147; // [esp+61Ch] [ebp-12Ch] BYREF
  vostok::math::float3 v148; // [esp+62Ch] [ebp-11Ch] BYREF
  vostok::math::float3 v149; // [esp+638h] [ebp-110h] BYREF
  vostok::math::float3 v150; // [esp+644h] [ebp-104h] BYREF
  stlp_std::pair<float,vostok::math::float3> v151; // [esp+650h] [ebp-F8h] BYREF
  vostok::math::float3 v152; // [esp+660h] [ebp-E8h] BYREF
  vostok::math::float3 v153; // [esp+66Ch] [ebp-DCh] BYREF
  vostok::math::float3 v154; // [esp+678h] [ebp-D0h] BYREF
  stlp_std::pair<float,vostok::math::float3> __x; // [esp+684h] [ebp-C4h] BYREF
  vostok::math::float3 v156; // [esp+694h] [ebp-B4h] BYREF
  vostok::math::float3 v157; // [esp+6A0h] [ebp-A8h] BYREF
  vostok::math::float3 v158; // [esp+6ACh] [ebp-9Ch] BYREF
  vostok::math::float3 v159; // [esp+6B8h] [ebp-90h] BYREF
  vostok::math::float3 v160; // [esp+6C4h] [ebp-84h] BYREF
  vostok::math::float3 v161; // [esp+6D0h] [ebp-78h] BYREF
  vostok::math::float3 d1; // [esp+6DCh] [ebp-6Ch] BYREF
  vostok::math::float3 p1; // [esp+6E8h] [ebp-60h] BYREF
  vostok::math::float3 p3; // [esp+6F4h] [ebp-54h] BYREF
  vostok::math::float3 d2; // [esp+700h] [ebp-48h] BYREF
  const vostok::render::culling::portal *portal; // [esp+70Ch] [ebp-3Ch]
  vostok::math::float3 p2; // [esp+710h] [ebp-38h] BYREF
  vostok::math::float3 p4; // [esp+71Ch] [ebp-2Ch] BYREF
  vostok::vectora<stlp_std::pair<float,vostok::math::float3> > portal_segments; // [esp+728h] [ebp-20h] BYREF
  vostok::sound::closets_point_predicate p; // [esp+738h] [ebp-10h]

  v79 = 0;
  m_object = this->m_graph.m_object;
  v77 = 0;
  portal = &m_object->m_portals.m_begin[portal_id];
  p1 = segment_start;
  p2 = segment_end;
  p3 = portal->m_points[0];
  p4 = portal->m_points[1];
  vostok::math::float3::float3(
    &d1,
    COERCE_UNSIGNED_INT(segment_end.x - segment_start.x),
    COERCE_UNSIGNED_INT(segment_end.y - segment_start.y),
    segment_end.z - segment_start.z);
  vostok::math::float3::float3(&d2, COERCE_UNSIGNED_INT(p4.x - p3.x), COERCE_UNSIGNED_INT(p4.y - p3.y), p4.z - p3.z);
  allocator.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>::vectora_allocator<vostok::fixed_vector<unsigned int,32>>(
    &v76,
    &allocator);
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
    (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&portal_segments,
    (const vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > *)&v76);
  v74 = vostok::sound::closest_point_on_segment(&v160, &p1, &p3, &d2);
  vostok::math::float3::float3(
    &v159,
    COERCE_UNSIGNED_INT(p1.x - v74->x),
    COERCE_UNSIGNED_INT(p1.y - v74->y),
    p1.z - v74->z);
  v72 = vostok::sound::closest_point_on_segment(&v161, &p1, &p3, &d2);
  v73 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v159);
  p.closest_point = *v72;
  p.min_val = v73;
  v71 = vostok::sound::closest_point_on_segment(&v157, &p1, &p3, &d2);
  vostok::math::float3::float3(
    &v156,
    COERCE_UNSIGNED_INT(p1.x - v71->x),
    COERCE_UNSIGNED_INT(p1.y - v71->y),
    p1.z - v71->z);
  v69 = *vostok::sound::closest_point_on_segment(&v158, &p1, &p3, &d2);
  v70 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v156);
  __x.first = v70;
  __x.second = v69;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &__x);
  v68 = vostok::sound::closest_point_on_segment(&v153, &p2, &p3, &d2);
  vostok::math::float3::float3(
    &v152,
    COERCE_UNSIGNED_INT(p2.x - v68->x),
    COERCE_UNSIGNED_INT(p2.y - v68->y),
    p2.z - v68->z);
  v66 = *vostok::sound::closest_point_on_segment(&v154, &p2, &p3, &d2);
  v67 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v152);
  v151.first = v67;
  v151.second = v66;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v151);
  v65 = vostok::sound::closest_point_on_segment(&v149, &p3, &p1, &d1);
  vostok::math::float3::float3(
    &v148,
    COERCE_UNSIGNED_INT(p3.x - v65->x),
    COERCE_UNSIGNED_INT(p3.y - v65->y),
    p3.z - v65->z);
  v63 = *vostok::sound::closest_point_on_segment(&v150, &p3, &p1, &d1);
  v64 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v148);
  v147.first = v64;
  v147.second = v63;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v147);
  v62 = vostok::sound::closest_point_on_segment(&v145, &p4, &p1, &d1);
  vostok::math::float3::float3(
    &v144,
    COERCE_UNSIGNED_INT(p4.x - v62->x),
    COERCE_UNSIGNED_INT(p4.y - v62->y),
    p4.z - v62->z);
  v60 = *vostok::sound::closest_point_on_segment(&v146, &p4, &p1, &d1);
  v61 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v144);
  v143.first = v61;
  v143.second = v60;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v143);
  p3 = portal->m_points[1];
  p4 = portal->m_points[2];
  vostok::math::float3::float3(&v142, COERCE_UNSIGNED_INT(p2.x - p1.x), COERCE_UNSIGNED_INT(p2.y - p1.y), p2.z - p1.z);
  d1 = v142;
  vostok::math::float3::float3(&v141, COERCE_UNSIGNED_INT(p4.x - p3.x), COERCE_UNSIGNED_INT(p4.y - p3.y), p4.z - p3.z);
  d2 = v141;
  v59 = vostok::sound::closest_point_on_segment(&v139, &p1, &p3, &d2);
  vostok::math::float3::float3(
    &v138,
    COERCE_UNSIGNED_INT(p1.x - v59->x),
    COERCE_UNSIGNED_INT(p1.y - v59->y),
    p1.z - v59->z);
  v57 = *vostok::sound::closest_point_on_segment(&v140, &p1, &p3, &d2);
  v58 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v138);
  v137.first = v58;
  v137.second = v57;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v137);
  v56 = vostok::sound::closest_point_on_segment(&v135, &p2, &p3, &d2);
  vostok::math::float3::float3(
    &v134,
    COERCE_UNSIGNED_INT(p2.x - v56->x),
    COERCE_UNSIGNED_INT(p2.y - v56->y),
    p2.z - v56->z);
  v54 = *vostok::sound::closest_point_on_segment(&v136, &p2, &p3, &d2);
  v55 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v134);
  v133.first = v55;
  v133.second = v54;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v133);
  v53 = vostok::sound::closest_point_on_segment(&v131, &p3, &p1, &d1);
  vostok::math::float3::float3(
    &v130,
    COERCE_UNSIGNED_INT(p3.x - v53->x),
    COERCE_UNSIGNED_INT(p3.y - v53->y),
    p3.z - v53->z);
  v51 = *vostok::sound::closest_point_on_segment(&v132, &p3, &p1, &d1);
  v52 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v130);
  v129.first = v52;
  v129.second = v51;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v129);
  v50 = vostok::sound::closest_point_on_segment(&v127, &p4, &p1, &d1);
  vostok::math::float3::float3(
    &v126,
    COERCE_UNSIGNED_INT(p4.x - v50->x),
    COERCE_UNSIGNED_INT(p4.y - v50->y),
    p4.z - v50->z);
  v48 = *vostok::sound::closest_point_on_segment(&v128, &p4, &p1, &d1);
  v49 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v126);
  v125.first = v49;
  v125.second = v48;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v125);
  p3 = portal->m_points[2];
  p4 = portal->m_points[3];
  v122 = p2.x - p1.x;
  v123 = p2.y - p1.y;
  v124 = p2.z - p1.z;
  d1.x = p2.x - p1.x;
  d1.y = p2.y - p1.y;
  d1.z = p2.z - p1.z;
  v119 = p4.x - p3.x;
  v120 = p4.y - p3.y;
  v121 = p4.z - p3.z;
  d2.x = p4.x - p3.x;
  d2.y = p4.y - p3.y;
  d2.z = p4.z - p3.z;
  v45 = vostok::sound::closest_point_on_segment(&v117, &p1, &p3, &d2);
  v46 = p1.y - v45->y;
  v47 = p1.z - v45->z;
  v116.x = p1.x - v45->x;
  v116.y = v46;
  v116.z = v47;
  v43 = *vostok::sound::closest_point_on_segment(&v118, &p1, &p3, &d2);
  v44 = vostok::math::float3_pod::squared_length(&v116);
  v115.first = v44;
  v115.second = v43;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v115);
  v40 = vostok::sound::closest_point_on_segment(&v113, &p2, &p3, &d2);
  v41 = p2.y - v40->y;
  v42 = p2.z - v40->z;
  v112.x = p2.x - v40->x;
  v112.y = v41;
  v112.z = v42;
  v38 = *vostok::sound::closest_point_on_segment(&v114, &p2, &p3, &d2);
  v39 = vostok::math::float3_pod::squared_length(&v112);
  v111.first = v39;
  v111.second = v38;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v111);
  v35 = vostok::sound::closest_point_on_segment(&v109, &p3, &p1, &d1);
  v36 = p3.y - v35->y;
  v37 = p3.z - v35->z;
  v108.x = p3.x - v35->x;
  v108.y = v36;
  v108.z = v37;
  v33 = *vostok::sound::closest_point_on_segment(&v110, &p3, &p1, &d1);
  v34 = vostok::math::float3_pod::squared_length(&v108);
  v107.first = v34;
  v107.second = v33;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v107);
  v30 = vostok::sound::closest_point_on_segment(&v105, &p4, &p1, &d1);
  v31 = p4.y - v30->y;
  v32 = p4.z - v30->z;
  v104.x = p4.x - v30->x;
  v104.y = v31;
  v104.z = v32;
  v28 = *vostok::sound::closest_point_on_segment(&v106, &p4, &p1, &d1);
  v29 = vostok::math::float3_pod::squared_length(&v104);
  v103.first = v29;
  v103.second = v28;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v103);
  p3 = portal->m_points[3];
  p4 = portal->m_points[0];
  v100 = p2.x - p1.x;
  v101 = p2.y - p1.y;
  v102 = p2.z - p1.z;
  d1.x = p2.x - p1.x;
  d1.y = p2.y - p1.y;
  d1.z = p2.z - p1.z;
  v97 = p4.x - p3.x;
  v98 = p4.y - p3.y;
  v99 = p4.z - p3.z;
  d2.x = p4.x - p3.x;
  d2.y = p4.y - p3.y;
  d2.z = p4.z - p3.z;
  v25 = vostok::sound::closest_point_on_segment(&v95, &p1, &p3, &d2);
  v26 = p1.y - v25->y;
  v27 = p1.z - v25->z;
  v94.x = p1.x - v25->x;
  v94.y = v26;
  v94.z = v27;
  v23 = *vostok::sound::closest_point_on_segment(&v96, &p1, &p3, &d2);
  v24 = vostok::math::float3_pod::squared_length(&v94);
  v93.first = v24;
  v93.second = v23;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v93);
  v20 = vostok::sound::closest_point_on_segment(&v91, &p2, &p3, &d2);
  v21 = p2.y - v20->y;
  v22 = p2.z - v20->z;
  v90.x = p2.x - v20->x;
  v90.y = v21;
  v90.z = v22;
  v18 = *vostok::sound::closest_point_on_segment(&v92, &p2, &p3, &d2);
  v19 = vostok::math::float3_pod::squared_length(&v90);
  v89.first = v19;
  v89.second = v18;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v89);
  v15 = vostok::sound::closest_point_on_segment(&v87, &p3, &p1, &d1);
  v16 = p3.y - v15->y;
  v17 = p3.z - v15->z;
  v86.x = p3.x - v15->x;
  v86.y = v16;
  v86.z = v17;
  v13 = *vostok::sound::closest_point_on_segment(&v88, &p3, &p1, &d1);
  v14 = vostok::math::float3_pod::squared_length(&v86);
  v85.first = v14;
  v85.second = v13;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v85);
  v10 = vostok::sound::closest_point_on_segment(&v83, &p4, &p1, &d1);
  v11 = p4.y - v10->y;
  v12 = p4.z - v10->z;
  v82.x = p4.x - v10->x;
  v82.y = v11;
  v82.z = v12;
  v8 = *vostok::sound::closest_point_on_segment(&v84, &p4, &p1, &d1);
  v9 = vostok::math::float3_pod::squared_length(&v82);
  v81.first = v9;
  v81.second = v8;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
    &portal_segments._M_impl,
    &v81);
  v6 = p;
  for ( i = portal_segments._M_impl._M_start; i != portal_segments._M_impl._M_finish; ++i )
  {
    if ( v6.min_val > i->first )
    {
      v6.min_val = i->first;
      *(_QWORD *)&v6.closest_point.x = *(_QWORD *)&i->second.x;
      v6.closest_point.z = i->second.z;
    }
  }
  v80 = v6;
  *result = p.closest_point;
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::~_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>(&portal_segments._M_impl);
  return result;
}
