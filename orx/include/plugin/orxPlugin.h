/* Orx - Portable Game Engine
 *
 * Orx is the legal property of its developers, whose names
 * are listed in the COPYRIGHT file distributed 
 * with this source distribution.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * @file orxPlugin.h
 * @date 06/09/2002
 * @author iarwain@orx-project.org
 *
 * @todo
 * - Add execute function for user register function + arg parser/checker
 * - Add execute/get function using ID (with hashtable)
 * - Add new string use for all string related operations, when systeme is done
 * - make a Complete Function Info Archiving (Global Info Structure (hash table?))
 */

/**
 * @addtogroup orxPlugin
 * 
 * Plugin module
 * This module provides functions for loading dynamic code into the core
 * engine and finding symbols within the dynamic modules.
 *
 * @{
 */


#ifndef _orxPLUGIN_H_
#define _orxPLUGIN_H_


#include "orxInclude.h"

#include "plugin/orxPluginType.h"


/*********************************************
 Function prototypes
 *********************************************/

/** Clock module setup.
 * \return nothing.
 */
extern orxDLLAPI orxVOID                        orxPlugin_Setup();
/** Initializes the plugin management engine.
 * \return orxSTATUS_SUCCESS/orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS                      orxPlugin_Init();

/** Shuts down the plugin management engine.
 * \return nothing.
 */
extern orxDLLAPI orxVOID                        orxPlugin_Exit();

/** Loads a plugin.
 * \param _zPluginFileName  The complete path of the plugin file, including its extension.
 * \param _zPluginName      The name that the plugin will be given in the plugin list.
 * \return The plugin handle on success, orxHANDLE_UNDEFINED on failure.
 */
extern orxDLLAPI orxHANDLE orxFASTCALL          orxPlugin_Load(orxCONST orxSTRING _zPluginFileName, orxCONST orxSTRING _zPluginName);

/** Loads a plugin using OS common library extension.
 * \param _zPluginFileName  The complete path of the plugin file, without its library extension.
 * \param _zPluginName      The name that the plugin will be given in the plugin list.
 * \return The plugin handle on success, orxHANDLE_UNDEFINED on failure.
 */
extern orxDLLAPI orxHANDLE orxFASTCALL          orxPlugin_LoadUsingExt(orxCONST orxSTRING _zPluginFileName, orxCONST orxSTRING _zPluginName);

/** Unloads a plugin.
 * \param _hPluginHandle The handle of the plugin to unload.
 * \return orxSTATUS_SUCCESS/orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS orxFASTCALL          orxPlugin_Unload(orxHANDLE _hPluginHandle);

/** Gets a function from a plugin.
 * \param _hPluginHandle The plugin handle.
 * \param _zFunctionName The name of the function to find.
 * \return orxPLUGIN_FUNCTION / orxNULL.
 */
extern orxDLLAPI orxPLUGIN_FUNCTION orxFASTCALL orxPlugin_GetFunction(orxHANDLE _hPluginHandle, orxCONST orxSTRING _zFunctionName);

/** Gets the handle of a plugin given its name.
 * \param _zPluginName The plugin name.
 * \return Its orxHANDLE / orxHANDLE_UNDEFINED
 */
extern orxDLLAPI orxHANDLE orxFASTCALL          orxPlugin_GetHandle(orxCONST orxSTRING _zPluginName);

/** Gets the name of a plugin given its handle.
 * \param _hPluginHandle The plugin handle.
 * \return The plugin name / empty string if not found.
 */
extern orxDLLAPI orxSTRING orxFASTCALL          orxPlugin_GetName(orxHANDLE _hPluginHandle);


#endif /* _orxPLUGIN_H_ */

/** @} */
