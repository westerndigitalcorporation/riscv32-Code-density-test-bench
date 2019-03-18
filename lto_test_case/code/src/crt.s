# 
# SPDX-License-Identifier: Apache-2.0
# Copyright 2019 Western Digital Corporation or its affiliates.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http:*www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

	.global	_start
	.type _start, @function
	.extern G_MY_GLOBAL
	
_start:
	#initialize Interrupt handler base
	la t0, G_MY_GLOBAL
	csrrw zero, 0xbc8, t0 #meivt
	

    j my_main


