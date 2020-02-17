#Timeouts

import asyncio

async def eternity():
	#sleep for one minute
	await asyncio.sleep(3)
	print('yay!')
	
async def main():
	#Wait for at most 1 second
	try:
		await asyncio.wait_for(eternity(), timeout=1.0)
	except asyncio.TimeoutError:
		print('timeout!')

asyncio.run(main())
		
