<?xml version="1.0" encoding="WINDOWS-1251"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/solar">
		<html>
			<head>
				<link rel="stylesheet" type="text/css" href="style.css"/>
			</head>
			<body>
				<br/>
				<h1>Планеты</h1>
				<br/>
					<div>
						<div class="table">
							<div id="first">
								<div>№</div>
								<div>Название</div>
								<div>Расстояние от солнца (а.е)</div>
								<div>Период обращения (г.)</div>
								<div>Период вращения вокруг своей оси (ч.)</div>
								<div>Масса относительно Земли</div>
								<div>Диаметр (км.)</div>
								<div>Количество спутников</div>
							</div>
							<xsl:for-each select="planet">
								<xsl:sort select="satellite_number" data-type="number"/>
								<xsl:sort select="@caption"/>
								<xsl:choose>
									<xsl:when test="./diametr &gt; 10000">
										<div id="large">
											<div><xsl:value-of select="position()"/></div>
											<xsl:call-template name="line" />
										</div>
									</xsl:when>
									<xsl:otherwise>
										<div id="small">
											<div><xsl:value-of select="position()"/></div>
											<xsl:call-template name="line" />
										</div>
									</xsl:otherwise>
								</xsl:choose>
							</xsl:for-each>
						</div>
					</div>
			</body>
		</html>
	</xsl:template>

	<xsl:template name="line">
		<div><xsl:value-of select="@caption"/></div>
		<div><xsl:value-of select="./distance"/></div>
		<div><xsl:value-of select="./circulation_period"/></div>
		<div><xsl:value-of select="./revolution_period"/></div>
		<div><xsl:value-of select="./weight"/></div>
		<div><xsl:value-of select="./diametr"/></div>
		<div><xsl:value-of select="./satellite_number"/></div>
	</xsl:template>
</xsl:stylesheet>