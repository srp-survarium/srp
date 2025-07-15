void __userpurge vostok::render::clouds::initialize(
        vostok::render::clouds *this@<ecx>,
        int a2@<esi>,
        const vostok::render::cloud_parameters *parameters)
{
  if ( *(_DWORD *)(a2 + 2288) )
    vostok::uninitialized_reference<vostok::render::cloud_simulation>::destroy(
      (vostok::uninitialized_reference<vostok::render::cloud_simulation> *)(a2 + 2184),
      (vostok::uninitialized_reference<vostok::render::cloud_simulation> *)(a2 + 2184));
  if ( a2 != -2184 )
    vostok::render::cloud_simulation::cloud_simulation(
      parameters->grid_width,
      parameters->grid_height,
      (vostok::render::cloud_simulation *)(a2 + 2184),
      parameters->grid_width);
  _InterlockedExchange((volatile __int32 *)(a2 + 2288), 1);
  if ( *(_DWORD *)(a2 + 2400) )
    vostok::uninitialized_reference<vostok::render::cloud_simulation>::destroy(
      (vostok::uninitialized_reference<vostok::render::cloud_simulation> *)(a2 + 2296),
      (vostok::uninitialized_reference<vostok::render::cloud_simulation> *)(a2 + 2296));
  if ( a2 != -2296 )
    vostok::render::cloud_simulation::cloud_simulation(
      parameters->grid_width,
      parameters->grid_height,
      (vostok::render::cloud_simulation *)(a2 + 2296),
      parameters->grid_width);
  _InterlockedExchange((volatile __int32 *)(a2 + 2400), 1);
  if ( *(_DWORD *)(a2 + 2512) )
    vostok::uninitialized_reference<vostok::render::cloud_simulation>::destroy(
      (vostok::uninitialized_reference<vostok::render::cloud_simulation> *)(a2 + 2408),
      (vostok::uninitialized_reference<vostok::render::cloud_simulation> *)(a2 + 2408));
  if ( a2 != -2408 )
    vostok::render::cloud_simulation::cloud_simulation(
      parameters->grid_width,
      parameters->grid_height,
      (vostok::render::cloud_simulation *)(a2 + 2408),
      parameters->grid_width);
  _InterlockedExchange((volatile __int32 *)(a2 + 2512), 1);
  *(_DWORD *)(a2 + 2704) = -1;
  *(_DWORD *)(a2 + 2708) = -1;
}
